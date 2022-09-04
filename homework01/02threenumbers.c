#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%i%i%i", &a, &b, &c);

	if (a + 1 == b && b + 1 == c || a - 1 == b && b - 1 == c)
		printf("Consecutive ");
	if (a < b && b < c)
		printf("Increasing\n");
	else if (a > b && b > c)
		printf("Decreasing\n");
	else if (a == b && b == c)
		printf("Equal\n");
	else
		printf("None\n");
}