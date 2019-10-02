// 题目：求1 + 2 ! + 3 ! + ... + 20 !的和
// 程序分析：此程序只是把累加变成了累乘。
// 2.程序源代码：
#include <stdio.h>
void main()
{
    int n, i;
    int s = 1, sum = 0;
    scanf("-%d", &n);
    for (i = 1; i <= n; i++)
    {
        s = s * i;
        sum = sum + s;
    }
    printf("sum=%d %d", sum, n);
}