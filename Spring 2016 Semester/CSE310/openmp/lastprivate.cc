#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, a, n;
	printf( "Testing the lastprivate construct\n" );
	printf( "Give an upper bound for the for loop: \n" );
	scanf( "%d", &n );

	printf( "Before the parallel region:\n");
	printf( "Arbirtary values for a = %d and i = %d\n\n", a, i );


#pragma omp parallel for private(i) lastprivate(a) num_threads(4)
	for( i = 0; i < n; i++ )
	{	
		a = i+1;
		printf( "Thread %d has the value a = %d for i = %d\n", omp_get_thread_num(), a, i );
	} /* -- End of parallel region -- */

	printf( "\nAfter the parallel region:\n" );
	printf( "\nThe value of a after parallel for: a = %d\n", a );
		
	return(0);
}
