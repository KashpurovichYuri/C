#include <stdio.h>
#include <limits.h>

int main()
{
	int n, len = 0, max = INT_MIN;
	scanf("%i", &n);

	while (n != 1)
	{
		printf("%i ", n);
		if (n > max)
			max = n;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = 3 * n + 1;
		len++;
	}

	printf("%i\n", n);
	if (n > max)
		max = n;
	len++;
	printf("Length = %i, Max = %i\n", len, max);
}