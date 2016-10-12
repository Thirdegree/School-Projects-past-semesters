#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<omp.h>

void funcA()
{
	sleep( 1 );
	printf( "In funcA: this section executed by thread %d\n", omp_get_thread_num() );
}

void funcB()
{
	sleep( 2 );
	printf( "In funcB: this section executed by thread %d\n", omp_get_thread_num() );
}

int main()
{

#pragma omp parallel num_threads(4)
{
	#pragma omp sections
	{
		#pragma omp section
			(void) funcA();

		#pragma omp section
			(void) funcB();
	} /* -- End of sections block -- */
} /* -- End of parallel region -- */
		
}
