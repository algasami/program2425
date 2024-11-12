#include <stdio.h>

/*
[10] #define N 10
int A[N][N], B[N][N];
Write a function that can compute the matrix multiplication of two 2-D N*N integer matrices in
which it must call another function to compute inner product of a row in A and a column in B that
uses the declaration of int (*p)[N].
*/

#define N 3

/**
 * We trick the program into thinking b is a column of continuous values, how?
 * 1 2 |3|
 * 4 5 |6|
 * 7 8 |9|
 * In C, if col_b is int[?] then col_b = 3 4 5 6 7 8 9,
 * so we say col_b is an array of array of size N,
 * so when we do *(col_b[i]), focus on col_b[i], the offset should be N (logically),
 * we move a whole N everytime we increase i, instead of 1.
 * This is an important concept called logical pointer arithmetic (LPA) as opposed to physical pointer arithmetic.
 */

int inner_product(int row_a[N], int (*col_b)[N]) // col_b is a pointer(here treated as an array) pointing to arrays of size N
{
	int prod = 0;
	for (int i = 0; i < N; i++)
	{
		prod += row_a[i] * *(col_b[i]);
	}
	return prod;
}

/**
 * More readable but less elegant in some ways -_-
 */
int inner_product_raw(int row_a[N], int col_start[N * N])
{
	int prod = 0;
	for (int i = 0; i < N; i++)
	{
		prod += row_a[i] * (col_start[i * N]);
	}
	return prod;
}

void multiply(int A[N][N], int B[N][N], int NEW[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			NEW[i][j] = inner_product(A[i], (int(*)[N]) & B[0][j]);
			// NEW[i][j] = inner_product_raw(A[i], &B[0][j]);
		}
	}
}

void input_mat(int MAT[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &MAT[i][j]);
		}
	}
}

void output_mat(int MAT[N][N])
{
	for (int i = 0; i < N; i++)
	{
		printf("%d", MAT[i][0]);
		for (int j = 1; j < N; j++)
		{
			printf(" %d", MAT[i][j]);
		}
		putchar('\n');
	}
}

int main()
{
	int A[N][N], B[N][N], C[N][N];
	input_mat(A);
	input_mat(B);
	multiply(A, B, C);
	output_mat(C);
	return 0;
}