// 求12所有的约数
// 12 1/2/3/4/6/12 2 2 3
// 6 1/2/3/6 2 3

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, i;
    scanf("%d", &n);
    for (i = n; i >= 1; i--)
    {
        if (n % i == 0)
            printf("%d,", i);
    }
    getchar();
    return 0;
}
