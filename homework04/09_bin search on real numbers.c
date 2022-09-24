#include <stdio.h>
#include <math.h>

double func(double x)
{
	return exp(x) * log(x) - 7;
}

const float eps = 1e-6;
double bin_search(float l, float r)
{
	while (fabs(r - l) > eps)
	{
		double mid = (l + r) / 2;
		if (func(mid) >= 0)
			r = mid;
		else
			l = mid;
	}

	return l;
}

int main()
{	
	double left = 1, right = 5;

	printf("%lf\n", bin_search(left, right));
}
