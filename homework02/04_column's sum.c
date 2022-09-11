#include <stdio.h>

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);

	int a[1000];
	for (int i = 0; i < n * m; ++i)
		scanf("%i", &a[i]);
	
	int sum = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{	
			sum += a[i + j * m];
		}

		printf("%i ", sum);
		sum = 0;
	}

	printf("\n");
}
