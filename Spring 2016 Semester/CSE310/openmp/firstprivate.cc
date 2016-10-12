#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, *a, vlen, index, n, tid;
	printf( "Testing the firstprivate construct\n" );
	printf( "Give the size of the thread-specific section, n: \n" );
	scanf( "%d", &n );

	index = 4;

	vlen = index+n*3;

	printf( "The size, vlen, of array a is index*n*num_threads = %d\n", vlen );

	if( ( a = (int * ) malloc( vlen * sizeof(int) ) ) == NULL )
		perror( "Error allocating a\n" );

	/* Initialize vector a with negative values.										*/

	printf( "Before the parallel region:\n" );
	for( i = 0; i < vlen; i++ )
	{
		a[i] = -i-1;
		printf( "a[%d] = %d\n", i, a[i] );
	}

	/* Each thread in a parallel region needs access to a thread-specific section of a	*/
	/* vector but access starts at a certain (nonzero) offset. The intial value of 		*/
	/* index is initialized to the required offset from the first element of a. The		*/
	/* length of each thread's section of the array is given by n. The thread-specific	*/
	/* section is given by index += n*tid which uses the initial value of index to		*/
	/* account for the offset.															*/

#pragma omp parallel default(none) firstprivate(index) private(i,tid) shared(n,a) num_threads(3)
{
	tid = omp_get_thread_num(); /* Get the thread number */

	index += n*tid;

	for( i = index; i < index+n; i++ )
	{	
		a[i] = tid + 1;
		printf( "Thread %d sets a[%d]=%d\n", omp_get_thread_num(), i, a[i] );
	}
} /* -- End of parallel region -- */

	printf( "After the parallel region:\n" );
	for( i = 0; i < vlen; i++ )
		printf( "a[%d] = %d\n", i, a[i] );
		
	free(a);
	return(0);
}
