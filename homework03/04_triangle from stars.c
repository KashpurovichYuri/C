#include <stdio.h>

void triangle(int n)
{
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}

		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%i", &n);

	triangle(n);
}
