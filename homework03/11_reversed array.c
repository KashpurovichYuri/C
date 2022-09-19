#include <stdio.h>

#define N 1000

void reverse(int array[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
}

int main()
{
	int size;
	scanf("%i", &size);

	int array[N];
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);

	reverse(array, size);
	for (int i = 0; i < size; i++)
		printf("%i ", array[i]);
}
