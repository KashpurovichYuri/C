#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	int i = 1, j = 1;
	while (i <= n)
	{
		a[2 * n - j] = a[n - i];
		a[2 * n - j - 1] = a[n - i];
		j += 2;
		++i;
	}

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < 2 * n; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
