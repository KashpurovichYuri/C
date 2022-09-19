#include <stdio.h>

int sum_of_digits_rec(int x)
{
	if (x == 0)
		return 0;

	return x % 10 + sum_of_digits_rec(x / 10);
}

int main()
{
	int x;
	scanf("%i", &x);

	printf("%i\n", sum_of_digits_rec(x));
}
