#include <stdio.h>
#include <math.h>

const float step = 1e-2;
const float eps = 1e-10;

double gamma_function(double x)
{
	double sum = 0, sq = 1;
	double left = 0;
	
	while (left < 100)
	{
		sq = (pow(left, x - 1) * exp(-left) + pow(left + step, x - 1) * exp(-left - step)) * step / 2;
		sum += sq;
		left += step;
	}

	while(fabs(sq) > eps)
	{
		sq = (pow(left, x - 1) * exp(-left) + pow(left + step, x - 1) * exp(-left - step)) * step / 2;
		sum += sq;
		left += step;
	}
	return sum;
}

int main()
{	
	double x;
	scanf("%lf", &x);

	printf("%lf\n", gamma_function(x));
}
