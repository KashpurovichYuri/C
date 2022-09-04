#include <stdio.h>

int main()
{
	int n, m;
	scanf("%i%i", &n, &m);

	int sum_n = 0;
	for (int i = 0; i <=n; ++i)
	{
		int sum_m = 0;
		for (int j = 0; j <= m; ++j)
		{
			if ((i + j) % 2 == 0) 
				sum_m += i * j;
			else
				sum_m -= i * j;
		}
		sum_n += sum_m;
	}

	printf("%i\n", sum_n);
}