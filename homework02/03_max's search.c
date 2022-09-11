#include <stdio.h>

int main()
{
	int n;
	
	int a[1000];

	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);
	
	if (n == 1)
		printf("%i\n", 0);
	else if (n == 2)
	{
		if (a[0] > a[1])
			printf("%i\n", 0);
		else
			printf("%i\n", 1);
	}
	else
	{
		int l = -1, r = n;

		while (r > l + 1)
		{
			int mid = (l + r) / 2;
			if (a[mid] >= a[mid + 1])
				r = mid;
			else
				l = mid;
		}

		printf("%i\n", r);
	}
}
