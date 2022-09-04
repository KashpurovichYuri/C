#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	scanf("%i", &n);

	int min = INT_MAX;
	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%i", &a);
		if (a < min && a % 2 == 0)
			min = a;
		if (a > max && a % 2 == 1)
			max = a;
	}
	if (min == INT_MAX && max == INT_MIN)
		printf("None None\n");
	else if (min == INT_MAX)
		printf("None %i\n", max);
	else if (max == INT_MIN)
		printf("%i None\n", min);
	else
		printf("%i %i\n", min, max);
}
/*
We expect that value of a can't be INT_MIN or INT_MAX
*/
