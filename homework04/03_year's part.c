#include <stdio.h>

float yearfrac(int y, int d)
{
	if (y % 4 == 0)
		return (float) d / 366;
	else
		return (float) d / 365;
}

int main()
{
	int year, day;
	scanf("%i%i", &year, &day);

	printf("%f\n", yearfrac(year, day));
}
