#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int ic, i, n;
	printf( "Example of the atomic construct\n" );
	printf( "Give an upper bound on the for loop:\n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n);

	ic = 0;

#pragma omp parallel for shared(n,ic) private(i) num_threads(4)
	for( i = 0; i < n; i++ )
	{
		/* The atomic construct may only be used together with an expression 	*/
		/* statement in C/C++, which means that it applies a simple, binary 	*/
		/* operation such as an increment or decrement to the value on the 		*/
		/* left-hand side. 														*/

		#pragma omp atomic
			ic++;
	} /* -- End of parallel region -- */

	printf( "Count should equal n = %d\n", n );
	printf( "Value of counter after parallel region: %d\n", ic );
	return(0);
}
