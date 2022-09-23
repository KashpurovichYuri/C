#include <stdio.h>

#define MAX 100

void assign(float [*][*], float [*][*], int);
void multiply(float [*][*], float [*][*], float [*][*], int);
void power(float [*][*], float [*][*], int, int);
void quick_power(float [*][*], float [*][*], int, int);

void assign(float A[MAX][MAX], float B[MAX][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}

void multiply(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			float sum = 0;
	
			for (int k = 0; k < n; ++k)
			{
				sum += A[i][k] * B[k][j];
			}

			C[i][j] = sum;
		}
	}
}


void power(float A[MAX][MAX], float C[MAX][MAX], int n, int k)
{
	float B[MAX][MAX];
	assign(A, B, n);

	for (int i = 1; i < k; i++)
	{	
		multiply(A, B, C, n);
		assign(C, B, n);
	}
}

void quick_power(float A[MAX][MAX], float C[MAX][MAX], int n, int k)
{
	float B[MAX][MAX];
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

	float a[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%f", &a[i][j]);
	
	float c[MAX][MAX];
	quick_power(a, c, n, k);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%f ", c[i][j]);
		}

		printf("\n");
	}	
}
