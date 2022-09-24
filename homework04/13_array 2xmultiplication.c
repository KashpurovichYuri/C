#include <stdio.h>

void mult2_array(int* p, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        p[i] *= 2;
}

int main()
{	
    size_t size = 10;
    int a[10] = {10, 20, 30, 40, 50};
    int* pa = &a[0];
    
    mult2_array(pa, size);
    for (size_t i = 0; i < size; ++i)
        printf("%i ", pa[i]);
}
