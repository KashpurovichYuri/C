#include <stdio.h>

#define N 1000

int count_even(int array[], int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] % 2 == 0)
		{
			count += 1;
		}
	}

	return count;
}

int main()
{
	int size;
	scanf("%i", &size);

	int array[N];
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);

	printf("%i\n", count_even(array, size));
}
