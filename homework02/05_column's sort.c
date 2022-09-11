/* There is the selection sort in this code */

#include <stdio.h>

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);

	int a[100][100];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%i", &a[i][j]);
	
	for (int j = 0; j < m; ++j)
	{
		for (int i = 0; i < n; ++i)
		{	
			int ind_min = i;
			for (int k = i; k < n; ++k)
			{
				if (a[ind_min][j] > a[k][j])
					ind_min = k;
			}
			int temp = a[i][j];
			a[i][j] = a[ind_min][j];
			a[ind_min][j] = temp;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%i ", a[i][j]);
		}

		printf("\n");
	}	
}
