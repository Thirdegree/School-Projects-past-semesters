#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{

	int i, j, n;
	printf( "Example of schedule clause\n" );
	printf( "Give an upper bound on the number of iterations: \n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n );

	/* The outer loop is parallelized with the loop construct. The workload in the inner	*/
	/* loop depends on the value of the outer loop iteration variable i. Therefore, the 	*/
	/* workload is not balanced, and the static schedule is probably not the best choice.	*/

#pragma omp parallel for default(none) schedule(runtime) private(i,j) shared(n) num_threads(4)
	for( i = 0; i < n; i++ )
	{
		printf( "Iteration %d executed by thread %d\n", i, omp_get_thread_num() );
		for( j = 0; j < i; j++ )
			system( "sleep 1" );
	} /* -- End of parallel for -- */

	return(0);
}
