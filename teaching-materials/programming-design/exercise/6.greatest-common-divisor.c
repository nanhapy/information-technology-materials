
// 题目：输入两个正整数m和n，求其最大公约数和最小公倍数。
// 程序分析：
// 穷举法：分别列出两整数的所有约数，并找出最大的公约数。
// 素因数分解：分别列出两数的素因数分解式，并计算共同项的乘积。
// 短除法：两数除以其共同素因数，直到两数互素时，所有除数的乘积即为最大公约数。
// 辗转相除法：两数相除，取余数重复进行相除，直到余数为0时，前一个除数即为最大公约数。
// gcd(a,b) = gcd(b,a mod b) (a>b 且a mod b 不为0)
#include <stdio.h>
main()
{
    int a, b, num1, num2, temp;
    printf("please input two numbers:\n");
    scanf("%d,%d", &num1, &num2);
    // if (num1 < num2)
    // {
    //     temp = num1;
    //     num1 = num2;
    //     num2 = temp;
    // }
    // a = num1;
    // b = num2;
    // while (b != 0) /*利用辗除法，直到b为0为止*/
    // {
    //     temp = a % b;
    //     a = b;
    //     b = temp;
    // }
    // printf("gcd:%d\n", a);
    // printf("lcm:%d\n", num1 * num2 / a);

    printf("gcd:%d\n", gcd(num1, num2));
    printf("lcm:%d\n", lcm(num1, num2));
    getch();
}

int gcd(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}