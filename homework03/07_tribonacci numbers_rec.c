#include <stdio.h>

int trib(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	
	return trib(n - 3) + trib(n - 2) + trib(n - 1);
}

int main()
{
	int n;
	scanf("%i", &n);

	printf("%i\n", trib(n));
}
