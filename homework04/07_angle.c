#include <stdio.h>
#include <math.h>

double distance(double x1, double x2, double y1, double y2)
{
	return sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

double length(double x1, double x2)
{
	return distance(x1, x2, 0, 0);
}

double scalar_product(double x1, double x2, double y1, double y2)
{
	return x1 * y1 + x2 * y2;
}

double angle_rad(double x1, double x2, double y1, double y2)
{
	return acos(scalar_product(x1, x2, y1, y2) / (length(x1, x2) * length(y1, y2)));
}

const double pi = 3.14159265359;
double to_degrees(double rad)
{
	return rad * 180 / pi;
}

int main()
{	
	double x1, x2, y1, y2;
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

	printf("%lf\n", to_degrees(angle_rad(x1, x2, y1, y2)));
}
