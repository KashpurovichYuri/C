#include <stdio.h>
#include <math.h>

unsigned long long fact(int n, int k)
{
	unsigned long long result = 1;
	for (int i = n - k; i <= n; ++i)
		result *= i;

	return result;
}

const float pi = 3.141593;
float ball_measure(int r, int n)
{
	if (n % 2 == 0)
		return pow(pi, n / 2) / fact(n / 2, n / 2 - 1) * pow(r, n);
	else
		return 2 * pow(4 * pi, n / 2) * pow(r, n) / fact(n, n / 2);
}

float cube_measure(int r, int n)
{
	return pow(2 * r, n);
}

int main()
{	
	int rad = 1;

	int deg;
	scanf("%i", &deg);

	printf("%f\n", cube_measure(rad, deg) / ball_measure(rad, deg));
}
