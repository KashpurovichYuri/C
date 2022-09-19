#include <stdio.h>

void alic(int);
void bob(int);

void alice(int n)
{
	n = n * 3 + 1;
	printf("Alice: %3i\n", n);
	bob(n);
}

void bob(int n)
{
	n /= 2;
	if (n == 1)
	{
		printf("Bob: %5i", n);
		return;
	}
	printf("Bob: %5i\n", n);

	if (n % 2 == 0)
		bob(n);
	else
		alice(n);
}

int main()
{
	int x;
	scanf("%i", &x);

	alice(x);
}
