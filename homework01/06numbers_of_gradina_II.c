#include <stdio.h>
#include <limits.h>

int main()
{	
	int a, b;
	scanf("%i%i", &a, &b);
	int max_len = INT_MIN, max_k = 0;

	for (int k = a; a <= k && k <= b; ++k)
	{
		int n = k;
		int len = 0;
		while (n != 1)
		{
			if (n % 2 == 0)
				n = n / 2;
			else
				n = 3 * n + 1;
			len++;
		}
		len++;
		if (len > max_len)
		{
			max_len = len;
			max_k = k;
		}
	}

	printf("%i %i\n", max_k, max_len);
}