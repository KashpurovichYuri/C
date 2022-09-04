#include <stdio.h>

int main()
{
	int n;
	scanf("%i", &n);

	int i = 1;
	while (i <= n)
	{
		printf("%3i -> %3i -> %3i\n", i, i * i, i * i * i);
		i++;
	}
}
