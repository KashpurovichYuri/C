#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double discr(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

const float eps = 1e-10;
int solve_quadratic(double a, double b, double c, double* px1, double* px2)
{
    // linear equation
    if (fabs(a) <= eps) 
    {
        if (fabs(b) <= eps)
        {
            if (fabs(c) <= eps)
            {
                printf("x belongs to real");
                exit(0);
            }
            else
                return 0;
        }
        else
        {
            *px1 = c / b;
            return 1;
        }
    }
    else
    {
        if (fabs(discr(a, b, c)) < eps)
        {
            *px1 = -b / (2 * a);
            return 1;
        }
        else if (discr(a, b, c) < 0)
            return 0;
        else
        {
            *px1 = (-b + sqrt(discr(a, b, c))) / 2 / a;
            *px2 = (-b - sqrt(discr(a, b, c))) / 2 / a;
            return 2;
        }
    }
}

int main()
{	
    double a = -2, b = 1, c = 1;
    double x1, x2;
    double* px1 = &x1;
    double* px2 = &x2;
    
    int num = solve_quadratic(a, b, c, px1, px2);
    if (num == 2)
        printf("%i solutions: %lf, %lf", num, *px1, *px2);
    else if (num == 1)
        printf("%i solution: %lf", num, *px1);
    else
        printf("%i solutions", num);
}
