#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	scanf("%i", &n);

	int min = INT_MAX;
	int max = INT_MIN;
	int count_min = 0, count_max = 0, count_equal = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%i", &a);
		if (a < min)
		{
			min = a;
			count_min++;
		}
		if (a > max)
		{
			max = a;
			count_max++;
		}
		if (a == min && a == max)
			count_equal++;
	}

	if (count_equal == n)
		printf("Equal\n");
	else if (count_max == n)
		printf("Increasing\n");
	else if (count_min == n)
		printf("Decreasing\n");
	else
		printf("None\n");
}
