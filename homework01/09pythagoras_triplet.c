#include <stdio.h>

int main()
{
	int n;
	scanf("%i", &n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{
			for (int k = j; k <= n; ++k)
			{
				int m = 2;
				if (i % m == 0 && j % m == 0 && k % m == 0)
					continue;
				
				m = 3;
				while (m <= k)
				{
					if (i % m == 0 && j % m == 0 && k % m == 0)
						break;
					m += 2;
				}
				if (i * i + j * j == k * k && m >= k)
					printf("%i %i %i\n", i, j, k);
			}
		}
	}
}