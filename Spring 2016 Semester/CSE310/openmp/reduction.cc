#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n, *a, local_sum, sum, tid;
	printf( "Example of the reduction construct\n" );
	printf( "Give an upper bound on the array a:\n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n);

	if( ( a = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating a\n" );

	for( i = 0; i < n; i++ )
		a[i] = i;

	sum = 0;

	/* The reduction clause gets the OpenMP compiler to generate code that 	*/
	/* performs the summation in parallel and that the variable sum will 	*/
	/* the result of a reduction.											*/

#pragma omp parallel for default(none) shared(n,a) reduction(+:sum) num_threads(4)
	for( i = 0; i < n; i++ )
		sum += a[i];
	/* -- End of parallel reduction -- */

	printf( "Sum should be n(n-1)/2 = %d\n", n*(n-1)/2 );
	printf( "Value of sum after parallel region: %d\n", sum );
	free(a);
	return(0);
}
