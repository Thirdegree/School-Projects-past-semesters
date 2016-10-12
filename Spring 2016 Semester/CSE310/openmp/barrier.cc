#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>
#include	<omp.h>

void print_time( int tid, char *s )
{
	time_t timer = time(NULL);

	printf( "Thread %d %s barrier at ", tid, s );
	printf( "%s", ctime( &timer ) );
}

int main()
{
	int tid;

	printf( "Illustrate the barrier construct\n" );

	/* To ensure that some threads in the team executing in the parallel region take	*/
	/* longer than others to reach the barrier, we get half of the threads to execute	*/
	/* the sleep 3 command, causing them to idle for three seconds. We then get each	*/
	/* thread to print out its thread number (stored in tid), a comment, and the time 	*/
	/* of day in hh:mm:ss. The barrier is then reached. After the barrier, each thread 	*/
	/* resumes execution and again prints out this information.							*/

#pragma omp parallel private(tid) num_threads(4)
{
	tid = omp_get_thread_num();
	if( tid < omp_get_num_threads()/2 )
		system( "sleep 3" );

	(void) print_time( tid, "before" );

	#pragma omp barrier

	(void) print_time( tid, "after" );
} /* -- End of parallel region -- */

	return(0);
}
