#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	int left, right;
	scanf("%i%i", &left, &right);

	for (int i = left; i < n - (right - left); ++i)
	{
		a[i] = a[i + right - left];
	}

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < n - (right - left); ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
