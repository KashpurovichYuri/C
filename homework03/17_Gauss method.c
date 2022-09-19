/* In this code we expect that determinat(A) != 0 */
/* This code need to be overworked (we need to use float type!) */

#include <stdio.h>

#define MAX 200

void swap_rows(int A[MAX][MAX], int n, int k, int m)
{
	for (int i = 0; i < n; i++)
	{
		int temp = A[k][i];
		A[k][i] = A[m][i];
		A[m][i] = temp;
	}
}

void solve_linear_system(int n, int A[MAX][MAX], int b[], int x[])
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
							A[m][k] -= A[m][j] / A[i][j] * A[i][k]; /* float should be there => float matrix we should consider */
						}
				}

				swap_rows(A[MAX][MAX], n, i, top);
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

	int A[MAX][MAX];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%i", &A[i][j]);

	int b[MAX], x[MAX] = {0};
	for (int i = 0; i < n; i++)
		scanf("%i", &b[i]);

	solve_linear_system(n, A[MAX][MAX], b, x);

	for (int i = 0; i < n; i++)
		printf("%i ", x[i]);
}
