#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	int new, ind;
	scanf("%i%i", &new, &ind);

	int temp = a[ind + 1];
	a[ind + 1] = new;
	for (int i = ind + 1; i < n + 1; ++i)
	{
		int b = a[i];
		a[i] = temp;
		temp = b;
	}


	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < n + 1; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
