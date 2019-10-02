// 题目：求一个3 * 3矩阵对角线元素之和
// 程序分析：利用双重for循环控制输入二维数组，再将a [i][i] 累加后输出。
// 2.程序源代码：
#include <stdio.h>
main()
{
    float a[3][3], sum = 0, sum2 = 0;
    
    int i, j;
    printf("please input rectangle element:\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            scanf("%f", &a[i][j]);

    // 1
    for (i = 0; i < 3; i++)
        sum = sum + a[i][i];
    for (i = 2; i >= 0; i--)
        sum2 = sum2 + a[2 - i][i];

    // 2
    for (int m = 0; i < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            if (n == m)
            {
                sum1 += a[n][m];
            }
            if (n + m == 2)
            {
                sum2 += a[n][m];
            }
        }
    }

    printf("reverce rectangle sum is %6.2f\n", sum);
    printf("rectangle sum is %6.2f", sum2);
}