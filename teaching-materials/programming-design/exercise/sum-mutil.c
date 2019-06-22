#include <stdio.h>

int main(int argc, char const *argv[])
{

    int a, b, c, sum, s;

    scanf("%d %d %d", &a, &b, &c);

    // sum = a + b;
    // s = a * b;

    // printf("sum = %d, s = %d", sum, s);

    int max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    if (max < c)
    {
        max = c;
    }

    // if (c > a && c > b)
    //     {
    //         max = c;
    //     }
    //     else
    //     {
    //         if (a > b)
    //         {
    //             max = a;
    //         }
    //         else
    //         {
    //             max = b;
    //         }
    //     }

    printf("max = %d", max);

    getch();

    return 0;
}
