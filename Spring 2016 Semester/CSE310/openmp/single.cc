#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n, a, *b;
	printf( "Testing the single construct\n" );
	printf( "Give an upper bound on the array b:\n" );
	scanf( "%d", &n );

	if( ( b = (int * ) malloc( n * sizeof(int) ) ) == NULL )
		perror( "Error allocating b\n" );

#pragma omp parallel shared(a,b) private(i) num_threads(4)
{
	/* Why do this? After all, every thread could just initialize the same location.	*/
	/* Depending on the data type, the processor details, and the compiler behaviour	*/
	/* each write to memory might be translated into a sequence of store instructions.	*/
	/* As a result, a data race could arise. Moreover, multiple stores to the same		*/
	/* memory address are bad for performance.											*/

	#pragma omp single
	{
		a = 10;
		printf( "Single construct executed by thread %d\n", omp_get_thread_num() );
	}

	/* A barrier is automatically inserted here */

	#pragma omp for
	for( i = 0; i < n; i++ )
	{	
		printf( "Thread %d is setting b[%d]=%d\n", omp_get_thread_num(), i, a );
		b[i] = a;
	}
} /* -- End of parallel region -- */

	printf( "After the parallel region:\n" );
	for( i = 0; i < n; i++ )
		printf( "b[%d] = %d\n", i, b[i] );
		
	free(b);
	return(0);
}
