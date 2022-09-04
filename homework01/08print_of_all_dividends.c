#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%i%i%i", &a, &b, &c);

	int i = a;
	while (i % c != 0)
		++i;
	while (i <= b)
	{
		printf("%i ", i);
		i += c;
	}
}