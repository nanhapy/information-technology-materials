#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, sum;

    c = 0, sum = 0;

    int d = 0;

    int c1 = 0;
    int c2 = 0;

    while (1)
    {
        scanf("%d", &d);

        if (d != 0)
        {
            // sum = sum + d;
            // c = c + 1; // 自增1

            if (d > 0)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        else
        {
            break;
        }
    }

    // if (c == 0)
    // {
    //     printf("0");
    // }
    // else
    // {
    //     float a = (float)sum / c; // 除以计数器

    //     printf("%f", a);
    // }

    printf("%d %d", c1, c2);

    // getch();

    return 0;
}
