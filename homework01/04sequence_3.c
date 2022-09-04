#include <stdio.h>
#include <limits.h>

int main()
{
	int n;
	scanf("%i", &n);

	int max = INT_MIN;
	int num_of_max = 0;
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%i", &a);
		if (a > max)
		{
			max = a;
			num_of_max = 1;
		}
		else if (a == max)
			num_of_max++;
	}
	
	printf("%i %i\n", max, num_of_max);
}
