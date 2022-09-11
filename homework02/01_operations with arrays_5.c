#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	int bound = 0, i = 0;
	while (i < n)
	{
		while (a[i] >= 0 && i < n - 1)
		{
			++i;
		}
		if (a[i] < 0)
		{
			int temp = a[bound];
			a[bound] = a[i];
			a[i] = temp;
			++bound;
		}
		++i;
	}

	int left = 0, right = bound;
	for (int i = left; i < n - (right - left); ++i)
	{
		a[i] = a[i + right - left];
	}

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < n - bound; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
