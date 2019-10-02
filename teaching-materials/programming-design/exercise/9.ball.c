
#include <stdio.h>
int main()
{
    float s = 100, h = 50;
    int i;
    for (i = 2; i <= 10; i++)
    {
        s = s + 2 * h;
        h = h / 2;
    }
    printf("%f	%f", s, h);
    return 0;
}