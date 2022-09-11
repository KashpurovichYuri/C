/* There is the selection sort in this code */

#include <stdio.h>

int main()
{
	int n;
	scanf("%i", &n);

	int a[10][10];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%i", &a[i][j]);

	int b[10][10];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%i", &b[i][j]);
	
	int c[10][10] = {{0}, {0}};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			for (int k = 0; k < n; ++k)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%i ", c[i][j]);
		}

		printf("\n");
	}	
}
