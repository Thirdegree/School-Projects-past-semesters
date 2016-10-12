#include	<stdio.h>
#include	<stdlib.h>

void mxv( int m, int n, double *a, double *b, double *c )
{
	int i, j;

	for( i=0; i<m; i++ )
	{
		a[i] = 0.0;
		for( j=0; j<n; j++ )
			a[i] += b[i*n+j] * c[j];
	}
}

int main( int argc, char *argv[] )
{
	/* Matrix B of size mxn times vector c, storing the result in vector a. */
	/* The result is obtained by computing the dot product of the rows of 	*/
	/* matrix B and vector c. */

	double *a, *b, *c;
	int i, j, m, n;

	printf( "Matrix B is mxn, give m and n:" );
	scanf( "%d %d", &m, &n );

	if( ( a = (double *) malloc( m*sizeof(double) ) ) == NULL )
		perror( "Memory alloaction error for a" );
	if( ( b = (double *) malloc( m*n*sizeof(double) ) ) == NULL )
		perror( "Memory alloaction error for b" );
	if( ( c = (double *) malloc( n*sizeof(double) ) ) == NULL )
		perror( "Memory alloaction error for c" );

	printf( "Initializing vector c (nx1)\n" );
	for( j=0; j<n; j++ )
	{
		c[j] = 2.0;
		printf( "%8.6f ", c[j] );
	}
	printf( "\n" );

	printf( "Initializing matrix B (mxn)\n" );
	for( i=0; i<m; i++ )
	{
		for( j=0; j<n; j++ )
		{
			b[i*n+j] = i;
			printf( "%8.6f ", b[i*n+j] );
		}
		printf( "\n" );
	}

	printf( "Executing mxv function for m = %d, n = %d\n", m, n );
	(void) mxv( m, n, a, b, c );

	printf( "Result is matrix a=Bc (mx1):\n" );
	for( i=0; i<m; i++ )
		printf( "%8.6f ", a[i] );
	printf( "\n" );

	free(a);
	free(b);
	free(c);
	return(0);
}
