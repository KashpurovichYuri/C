#include <stdio.h>

int main()
{
	int a[1000];

	int n;
	scanf("%i", &n);

	for (int i = 0; i < n; ++i)
		scanf("%i", &a[i]);

	// ||||| My code beetween reading array and printing it |||||
	
	int k;
	scanf("%i", &k);

	int lim;
	if ((k % n) < n / 2) 
		lim = k % n;
	else
		lim = n - k % n;

	int i = 0;
	while (i < lim)
	{
		int ind = -1, temp1 = a[i];
		while (ind != i)
		{
			if (ind == -1)
				ind = i;
			int temp2 = a[(ind + k) % n];
			a[(ind + k) % n] = temp1;
			temp1 = temp2;
			ind = (ind + k) % n;
		}

		++i;
	}

	// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||

	for (int i = 0; i < n; ++i)
		printf("%i ", a[i]);
	
	printf("\n");
}
