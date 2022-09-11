#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	for (int i = n; i < 2 * n; ++i)
		a[i] = a[i - n];

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < 2 * n; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
