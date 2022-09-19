#include <stdio.h>

#define MAX 100

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

int main()
{
	int n;
	scanf("%i", &n);

	int mat_a[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%i", &mat_a[i][j]);

	int mat_b[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%i", &mat_b[i][j]);
	
	int mat_c[MAX][MAX];
	multiply(mat_a, mat_b, mat_c, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%i ", mat_c[i][j]);
		}

		printf("\n");
	}	
}
