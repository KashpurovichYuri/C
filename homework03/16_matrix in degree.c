#include <stdio.h>

#define MAX 100

void assign(int [*][*], int [*][*], int);
void multiply(int [*][*], int [*][*], int [*][*], int);
void power(int [*][*], int [*][*], int, int);
void quick_power(int [*][*], int [*][*], int, int);

void assign(int A[MAX][MAX], int B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int sum = 0;
	
			for (int k = 0; k < n; ++k)
			{
				sum += A[i][k] * B[k][j];
			}

			C[i][j] = sum;
		}
	}
}


void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
	int B[MAX][MAX];
	assign(A, B, n);

	for (int i = 1; i < k; i++)
	{	
		multiply(A, B, C, n);
		assign(C, B, n);
	}
}

void quick_power(int A[MAX][MAX], int C[MAX][MAX], int n, int k)
{
	int B[MAX][MAX];
	assign(A, B, n);

	int i = 1;
	while (i * 2 < k)
	{
		multiply(B, B, C, n);
		assign(C, B, n);
		i *= 2;
	}

	while (i < k)
	{
		multiply(A, B, C, n);
		assign(C, B, n);
		i++;
	}
}

int main()
{
	int n, k;
	scanf("%i%i", &n, &k);

	int a[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%i", &a[i][j]);
	
	int c[MAX][MAX];
	quick_power(a, c, n, k);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%i ", c[i][j]);
		}

		printf("\n");
	}	
}
