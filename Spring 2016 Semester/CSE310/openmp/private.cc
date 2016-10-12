#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, a, n;
	printf( "Testing the private construct\n" );
	printf( "Give an upper bound for the for loop: \n" );
	scanf( "%d", &n );

	printf( "Before the parallel region:\n");
	//a = 55; i = 109; /* Arbitrary values */
	printf( "Arbirtary values for a = %d and i = %d\n\n", a, i );

	/* Each thread has a local copy of variables i and a.	*/
	/* If variable a had been specified in a shared clause, multiple threads would	*/
	/* attemp to update the same variable with different values in an uncontrolled	*/
	/* manner. The final value would depend on which thread happened to last update	*/
	/* a, i.e., a race condition. Therefore, the usage of a requires us to specify	*/
	/* it to be a private variable, ensuring that each thread has its own copy.		*/

#pragma omp parallel for private(i,a) num_threads(4)
	for( i = 0; i < n; i++ )
	{	
		a = i+1;
		printf( "Thread %d has the value a = %d for i = %d\n", omp_get_thread_num(), a, i );
	} /* -- End of parallel region -- */

	printf( "\nAfter the parallel region:\n" );
	printf( "The value a = %d and i = %d\n", a, i );
		
	return(0);
}
