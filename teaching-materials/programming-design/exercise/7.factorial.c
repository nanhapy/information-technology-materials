// 题目：求1 + 2 ! + 3 ! + ... + 20 !的和
// 程序分析：此程序只是把累加变成了累乘。 2.程序源代码：
#include <stdio.h>
main()
{
    float n, s = 0, t = 1;
    for (n = 1; n <= 20; n++)
    {
        t *= n;
        s += t;
    }
    printf("1+2!+3!...+20!=%e\n", s);
    getch();
}