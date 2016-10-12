#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n, *a, local_sum, sum, tid;
	printf( "Example of the critical construct\n" );
	printf( "Give an upper bound on the array a:\n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n);

	if( ( a = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating a\n" );

	for( i = 0; i < n; i++ )
		a[i] = i;

	sum = 0;

#pragma omp parallel shared(n,a,sum) private(tid,local_sum) num_threads(4)
{
	/* Within the parallel region each thread initializes local_sum. The iterations */
	/* of the #pragma omp for loop are distributed over the threads. This process	*/
	/* results in each thread computing a partial sum, stored in local_sum.			*/

	tid = omp_get_thread_num();
	local_sum = 0;

	#pragma omp for 
	for( i = 0; i < n; i++ )
	{
		local_sum += a[i];
	}

	/* The critical section is needed to avoid a data race condition when updating	*/
	/* variable sum. (A reduction clause can also be used.)							*/

	#pragma omp critical (update_sum)
	{
		sum += local_sum;
		printf( "Thread %d: local_sum = %d, sum = %d\n", tid, local_sum, sum );
	}
} /* -- End of parallel region -- */

	printf( "Sum should be n(n-1)/2 = %d\n", n*(n-1)/2 );
	printf( "Value of sum after parallel region: %d\n", sum );
	free(a);
	return(0);
}
