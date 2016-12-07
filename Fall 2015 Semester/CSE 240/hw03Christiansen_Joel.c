// Joel Christiansen

#define _CRT_SECURE_NO_WARNINGS  // Not show security related warning
#include <stdio.h>

//Q1: forward declarations (5 points)
//Create forward declarations for all the functions used

//Forward Declarations Code Here
void initialize_matrices(int[3][3], int[3][3], int[3][3]);
void fill_matrix(int[3][3]);
void add_matrices(int[3][3], int[3][3], int[3][3]);
void print_sum_matrix(int[3][3]);

int main()
{
    //Q2: define matrices (5 points)
    //Define three 3x3 integer matrices a, b, and c
    //(hint: a 3x3 matrix is the same as a 2D array with 3 rows and 3 columns)

    //CODE HERE
    int a[3][3];
    int b[3][3];
    int c[3][3];

    

    //Uncomment the following code once you've defined your matrices

    initialize_matrices(a, b, c);

    printf("Matrix a:\n");
    fill_matrix(a);

    printf("Matrix b:\n");
    fill_matrix(b);

    add_matrices(a, b, c);

    print_sum_matrix(c);

    

    return 0;
}

//Q3: initialize (10 points)
//loop through the matrices and set each integer value to 0
void initialize_matrices(int a[3][3], int b[3][3], int c[3][3])
{

    //CODE HERE
    for (int i = 0; i < 3; ++i)
    {
        /* code */
        for (int j = 0; j < 3; ++j)
        {
            /* code */
            a[i][j] = 0;
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }

}

//Q4: insert (10 points)
//Loop through the given matrix and fill it with input integers.
//Optional: You can prompt for input by printing "Enter the next integer: "
void fill_matrix(int matrix[3][3])
{

    //CODE HERE
    int num;
    for (int i = 0; i < 3; ++i)
    {
        /* code */
        for (int j = 0; j < 3; ++j)
        {
            /* code */
            scanf("%d", &num);
            matrix[i][j] = num;
        }
    }

}

//Q5: addition(10 points)
//Loop through and add together the matrices a and b. Store the sum in matrix c.
//(hint: the result for c[0][0] is the sum of a[0][0] and b[0][0])
void add_matrices(int a[3][3], int b[3][3], int c[3][3])
{

    //CODE HERE
    for (int i = 0; i < 3; ++i)
    {
        /* code */
        for (int j = 0; j < 3; ++j)
        {
            /* code */
            c[i][j] = a[i][j] + b[i][j];
        }
    }

}

//Q6: print(10 points)
//print the matrix c by row in the following format using tabs (\t):
// X     X     X
// X     X     X
// X     X     X
//(hint: printf( "%d\t", _ ) )
void print_sum_matrix(int c[3][3])
{

    //CODE HERE
    for (int i = 0; i < 3; ++i)
    {
        /* code */
        for (int j = 0; j < 3; ++j)
        {
            /* code */
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

}