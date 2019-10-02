#include <stdio.h>

void main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;

    int c = b;
    b = a;
    a = c;

    printf("a = %d, b = %d", a, b);
}
