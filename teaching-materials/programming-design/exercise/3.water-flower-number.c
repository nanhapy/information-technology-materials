// 水仙花数是指一个 3 位数，它的每个位上的数字的 3次幂之和等于它本身
// （例如：1^3 + 5^3+ 3^3 = 153）。

#include <stdio.h>

int main()
{
    printf("water flower number is:");
    int i, j, k, n;
    for (n = 100; n < 1000; n++)
    {
        i = n / 100; //335 / 100 = 3 
        j = n / 10 % 10;  335 / 10 = 33; 33 % 10 = 3
        k = n % 10;
        if (n == i * i * i + j * j * j + k * k * k)
        {
            printf("%-5d", n);
        }
    }

    return 0;
}

int intEquel(int a, int b)
{
    return a == b;
}