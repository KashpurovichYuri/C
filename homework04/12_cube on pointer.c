#include <stdio.h>

float cube(float* p)
{
    return *p * *p * *p;
}

int main()
{	
    float x = 8;
    float* px = &x;

    printf("%f\n", cube(px));
}
