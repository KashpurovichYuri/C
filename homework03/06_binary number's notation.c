#include <stdio.h>
#include <stdlib.h>

void print_binary(int x)
{
	if (x == 0)
		return;

	print_binary(x / 2);
	printf("%i", x % 2);
}

int main()
{
	int x;
	scanf("%i", &x);

	if (x == 0)
	{
		printf("0");
		exit(0);
	}

	print_binary(x);
}
