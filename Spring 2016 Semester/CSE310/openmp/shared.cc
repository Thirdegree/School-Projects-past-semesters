#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n, *a;
	printf( "Testing the shared construct\n" );
	printf( "Give an upper bound on the array a:\n" );
	scanf( "%d", &n );

	if( ( a = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating a\n" );

	for( i = 0; i < n; i++ )
		a[i] = 0;

	/* Vector a is declared to be shared, so all threads are able to read and write		*/
	/* element of a. Within the parallel loop, each thread will access the pre-existing	*/
	/* value of those elements a[i] of a that it is responsible for updating and will	*/
	/* compute their new values. After the parallel region is finished, all the new		*/
	/* values for elements of a will be in main memory, where the master thread can		*/
	/* access them.																		*/

#pragma omp parallel for shared(a) num_threads(4)
	for( i = 0; i < n; i++ )
	{	
		a[i] += i;
		printf( "Thread %d sets a[%d]=%d\n", omp_get_thread_num(), i, a[i] );
	} /* -- End of parallel region -- */

	printf( "After the parallel region:\n" );
	for( i = 0; i < n; i++ )
		printf( "a[%d] = %d\n", i, a[i] );
		
	free(a);
	return(0);
}
