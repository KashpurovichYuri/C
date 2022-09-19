#include <stdio.h>
#include <stdlib.h>

void print_even(int a, int b)
{
	a += abs(a % 2);

	for (int i = a; i <= b; i += 2)
	{
		printf("%i ", i);
	}
}

int main()
{
	int a, b;
	scanf("%i%i", &a, &b);

	print_even(a, b);
}