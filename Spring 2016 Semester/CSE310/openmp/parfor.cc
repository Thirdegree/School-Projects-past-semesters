#include	<stdio.h>
#include	<stdlib.h>
#include	<omp.h>

int main()
{
	int i, n;
	printf( "Use a parallel directive to define a parallel region\n" );
	printf( "Then share its work among threads via the for work-sharing directive\n" );
	printf( "Give an upper bound on the for loop:\n" );
	scanf( "%d", &n );
	printf( "n = %d\n", n);

	/* Though not strictly needed since this is enforced by the compiler, loop variable	*/
	/* i is explicitly declared to be a private variable (each thread will have its own	*/
	/* copy of i. Unless special action is taken, its value is undefined after the loop	*/
	/* has finished. Variable n is made shared.											*/

#pragma omp parallel shared(n) private(i) num_threads(4)
{
	#pragma omp for 
	for( i = 0; i < n; i++ )
		printf( "Thread %d executes loop iteration %d\n", omp_get_thread_num(), i );
} /* -- End of parallel region -- */

	return(0);
}
