#include <stdio.h>

int trib(int n)
{
	int trib[1000] = {0, 0, 1};

	for (int i = 3; i <= n; i++)
	{
		trib[i] = trib[i - 3] + trib[i - 2] + trib[i - 1];
	}

	return trib[n];
}

int main()
{
	int n;
	scanf("%i", &n);

	printf("%i\n", trib(n));
}
