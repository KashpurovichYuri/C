#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code between reading array and printing it |||||
	
	int bound = 0, i = 0;
	while (i < n)
	{
		while (a[i] % 2 == 0 && i < n - 1)
		{
			++i;
		}
		int temp = a[bound];
		a[bound] = a[i];
		a[i] = temp;
		++bound;
		++i;
	}

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
