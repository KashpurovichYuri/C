#include <stdio.h>

double pi_approx(int n)
{
	float sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 2 != 0)
			sum += (float) 1 / (2 * i - 1);
		else
			sum += (float) -1 / (2 * i - 1);
	}

	return 4 * sum;
}

int main()
{	
	int num;
	scanf("%i", &num);

	printf("%f\n", pi_approx(num));
}
