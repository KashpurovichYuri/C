#include <stdio.h>

int main()
{	
    printf("Literals:\n");
    printf("char: %6i\n", sizeof(char));
    printf("short: %5i\n", sizeof(short));
    printf("int: %7i\n", sizeof(1));
    printf("long long: %i\n", sizeof(1ll));
    printf("size_t: %4i\n", sizeof(size_t));
    printf("float: %5i\n", sizeof(1.0f));
    printf("double: %4i\n", sizeof(1.0));
    printf("int*: %6i\n", sizeof(int*));

    int a[10];
    printf("int[10]: %3i\n", sizeof(a));
}
