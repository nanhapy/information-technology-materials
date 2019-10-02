#include <stdio.h>
void main()
{
    float h = 100, t = 1, sum = 100;
    for (t = 1; t <= 10; t++)
    {
        h = h / 2;
        sum = sum + 2 * h;
    }
    sum = sum - h;
    printf("%f", sum);
}