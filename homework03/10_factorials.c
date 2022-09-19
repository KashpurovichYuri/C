#include <stdio.h>

#define N 1000

int fact(int x)
{
	if (x == 0)
		return 1;

	return x * fact(x - 1); 
}

void factorials(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = fact(array[i]);
	}
}

int main()
{
	int size;
	scanf("%i", &size);

	int array[N];
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);

	factorials(array, size);
	for (int i = 0; i < size; i++)
		printf("%i ", array[i]);
}
