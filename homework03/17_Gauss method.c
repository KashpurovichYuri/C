/* In this code we expect that determinat(A) != 0 */
/* This code need to be overworked */

#include <stdio.h>

#define MAX 200

void swap_rows(float A[MAX][MAX], int n, int k, int m)
{
	for (int i = 0; i < n; i++)
	{
		int temp = A[k][i];
		A[k][i] = A[m][i];
		A[m][i] = temp;
	}
}

void solve_linear_system(int n, float A[MAX][MAX], float b[], float x[])
{
	int top = 0;

	// straight step of Gauss' method
	for (int j = top; j < n; j++)
	{
		for (int i = top; i < n; i++)
		{
			if (A[i][j] != 0)
			{
				for (int k = j; k < n; k++)
				{
					for (int m = i; m < n; m++)
						{
							A[m][k] -= A[m][j] / A[i][j] * A[i][k];
						}
				}

				swap_rows(A, n, i, top);
				top++;
			}
		}
	}

	// back step of Gauss' method may be omited

	for (int i = n - 1; i > 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			x[i] -= A[i - 1][j] / A[i][i] * x[j];
		}
		x[i] += b[i] / A[i][i]; /* because we know that determinat(A) != 0 */
	}
}

int main()
{
	int n;
	scanf("%i", &n);

	float A[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%f", &A[i][j]);

	float b[MAX], x[MAX] = {0};
	for (int i = 0; i < n; i++)
		scanf("%f", &b[i]);

	solve_linear_system(n, A, b, x);

	for (int i = 0; i < n; i++)
		printf("%f ", x[i]);
}
