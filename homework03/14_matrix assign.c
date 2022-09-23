#include <stdio.h>

#define MAX 100

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

int main()
{
	int size;
	scanf("%i", &size);

	float mat_a[MAX][MAX], mat_b[MAX][MAX];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			scanf("%f", &mat_a[i][j]);

	assign(mat_a, mat_b, size);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%f ", mat_b[i][j]);
		}

		printf("\n");
	}
}
