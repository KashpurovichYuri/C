#include <stdio.h>
#include <math.h>

double distance(double x1, double x2, double y1, double y2)
{
	return sqrt((x1 - y1) * (x1 - y1) + (x2 - y2) * (x2 - y2));
}

const float eps = 1e-5;
int main()
{	
	double x1, x2, r1, y1, y2, r2;
	scanf("%lf%lf%lf%lf%lf%lf", &x1, &x2, &r1, &y1, &y2, &r2);

	double c_dist = distance(x1, x2, y1, y2);
	if(fabs(c_dist - (r1 + r2)) < eps)
		printf("Touch");
	else if (c_dist > r1 + r2)
		printf("Do not intersect");
	else
		printf("Intersect");
}
