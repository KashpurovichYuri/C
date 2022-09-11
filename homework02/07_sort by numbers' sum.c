/* There is the selection sort in this code */

#include <stdio.h>

int main()
{
	int n;
	scanf("%i", &n);

	int a[10000];
	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	for (int i = 0; i < n; ++i)
	{
		int ind_min = i, sum_ind_min, copy = a[ind_min];
		if (a[ind_min] < 0)
			copy = -copy;
		while(copy != 0)
		{
			sum_ind_min += copy % 10;
			copy /= 10;
		}

		for (int j = i; j < n; ++j)
		{	
			int sum = 0, copy = a[j];
			if (a[j] < 0)
				copy = -copy;
			while (copy != 0)
			{	
				sum += copy % 10;
				copy /= 10;
			}
			
			if (sum < sum_ind_min)
			{
				ind_min = j;
				sum_ind_min = sum;
			}
		}
		int temp = a[i];
		a[i] = a[ind_min];
		a[ind_min] = temp;
	}

	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
}
