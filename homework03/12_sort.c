// There is the selection sort in this code

#include <stdio.h>

#define N 1000

void sort(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int ind_min = i;

			if (array[ind_min] < array[j])
			{
				ind_min = j;
			}

			int temp = array[i];
			array[i] = array[ind_min];
			array[ind_min] = temp;
		}
	}
}

int main()
{
	int size;
	scanf("%i", &size);

	int array[N];
	for (int i = 0; i < size; i++)
		scanf("%i", &array[i]);

	sort(array, size);
	for (int i = 0; i < size; i++)
		printf("%i ", array[i]);
}
