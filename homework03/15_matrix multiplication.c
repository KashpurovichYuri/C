#include <stdio.h>

#define MAX 100

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

int main()
{
	int n;
	scanf("%i", &n);

	float mat_a[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%f", &mat_a[i][j]);

	float mat_b[MAX][MAX];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%f", &mat_b[i][j]);
	
	float mat_c[MAX][MAX];
	multiply(mat_a, mat_b, mat_c, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%f ", mat_c[i][j]);
		}

		printf("\n");
	}	
}
