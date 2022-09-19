#include <stdio.h>
#include <stdlib.h>

#define N 1000

void last_digits(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = abs(array[i]) % 10;
	}
}

int main()
{
	int size;
	scanf("%i", &size);

	int array[N];
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);

	last_digits(array, size);
	for (int i = 0; i < size; i++)
		printf("%i ", array[i]);
}
