#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n, *a, *b;
	printf( "Two work-shared loops, or parallel loops\n" );
	printf( "The compiler does not necessarily map iterations of the second loop in the\n" );
	printf( "same way as it does for the first loop\n" );
	printf( "Give an upper bound on the for loops:\n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n);

	if( ( a = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating a\n" );
	if( ( b = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating b\n" );

#pragma omp parallel shared(n,a,b) private(i) num_threads(4)
{
	#pragma omp for 
	for( i = 0; i < n; i++ )
	{
		a[i] = i;
		printf( "Thread %d initializing a[%d]=%d\n", omp_get_thread_num(), i, a[i] );
	}

	/* There is an implied barrier at the end of this for loop, so we can be certain that 	*/
	/* all values of a have been created by the time we being to use them.					*/

	#pragma omp for
	for( i = 0; i < n; i++ )
	{
		b[i] = 2 * a[i];
		printf( "Thread %d setting b[%d]= 2*%d = %d\n", omp_get_thread_num(), i, a[i], b[i] );
	}
} /* -- End of parallel region -- */

	free(a);
	free(b);
	return(0);
}
