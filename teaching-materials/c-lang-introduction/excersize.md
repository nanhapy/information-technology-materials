# 习题

## 企业发放的奖金根据利润提成

> 利润(I)低于或等于 10 万元时，奖金可提 10%；  
>  利润高于 10 万元，低于 20 万元时，低于 10 万元的部分按 10%提成，高于 10 万元的部分，可提成 7.5%；  
>  20 万到 40 万之间时，高于 20 万元的部分，可提成 5%；  
>  40 万到 60 万之间时高于 40 万元的部分，可提成 3%；  
>  60 万到 100 万之间时，高于 60 万元的部分，可提成 1.5%；  
>  高于 100 万元时，超过 100 万元的部分按 1%提成。  
>  从键盘输入当月利润 I，求应发放奖金总数？

- 程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成长整型。

```c
#include<stdio.h>
int main()
{
    double i;
    double bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
    printf("你的净利润是：\n");
    scanf("%lf",&i);
    bonus1=100000*0.1;
    bonus2=bonus1+100000*0.075;
    bonus4=bonus2+200000*0.05;
    bonus6=bonus4+200000*0.03;
    bonus10=bonus6+400000*0.015;
    if(i<=100000) {
        bonus=i*0.1;
    } else if(i<=200000) {
        bonus=bonus1+(i-100000)*0.075;
    } else if(i<=400000) {
        bonus=bonus2+(i-200000)*0.05;
    } else if(i<=600000) {
        bonus=bonus4+(i-400000)*0.03;
    } else if(i<=1000000) {
        bonus=bonus6+(i-600000)*0.015;
    } else if(i>1000000) {
        bonus=bonus10+(i-1000000)*0.01;
    }
    printf("提成为：bonus=%lf",bonus);

    printf("\n");
}
```

## 枚举求值

> 一个整数，它加上 100 后是一个完全平方数，再加上 168 又是一个完全平方数，请问该数是多少？

- 程序分析：

  假设该数为 x。

  1、则：x + 100 = n2, x + 100 + 168 = m2

  2、计算等式：m2 - n2 = (m + n)(m - n) = 168

  3、设置： m + n = i，m - n = j，i \* j =168，i 和 j 至少一个是偶数

  4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。

  5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。

  6、由于 i \* j = 168， j>=2，则 1 < i < 168 / 2 + 1。

  7、接下来将 i 的所有数字循环计算即可。

```c
#include <stdio.h>

int main (void)
{
    int  i, j, m, n, x;
    for (i = 1; i < 168 / 2 + 1; i++)
    {
        if (168 % i == 0)
        {
            j = 168 / i;
            if ( i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
            {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf ("%d + 100 = %d * %d\n", x, n, n);
                printf ("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }
    return 0;
}
```

## 输出国际象棋棋盘

> 要求输出国际象棋棋盘

- 程序分析：  
  国际象棋棋盘由 64 个黑白相间的格子组成，分为 8 行\*8 列。用 i 控制行，j 来控制列，根据 i+j 的和的变化来控制输出黑方格，还是白方格。

```c
#include<stdio.h>

int main()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if((i+j)%2==0)
                printf("%c%c",219,219);
            else printf("  ");
        printf("\n");
    }
    return 0;
}
```

## 兔子生崽

> 有一对兔子，从出生后第 3 个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前 40 个月即可）

- 程序分析  
  兔子的规律为数列 1,1,2,3,5,8,13,21....，即下个月是上两个月之和（从第三个月开始）。

```c
#include<stdio.h>

int main()
{
    int f1=1,f2=1,i;
    for(i=1;i<=20;i++)
    {
        printf("%12d%12d",f1,f2);
        if(i%2==0) printf("\n");
        f1=f1+f2;
        f2=f1+f2;
    }

    return 0;
}
```

## 判断素数

> 判断 101 到 200 之间的素数。

- 程序分析：  
  判断素数的方法：用一个数分别去除 2 到 sqrt(这个数)，如果能被整除， 则表明此数不是素数，反之是素数。

```c
#include <stdio.h>

int main()
{
    int i,j;
    int count=0;

    for (i=101; i<=200; i++)
    {
        for (j=2; j<i; j++)
        {
        // 如果j能被i整除在跳出循环
            if (i%j==0)
                break;
        }
        // 判断循环是否提前跳出，如果j<i说明在2~j之间,i有可整除的数
        if (j>=i)
        {
            count++;
            printf("%d ",i);
            // 换行，用count计数，每五个数换行
            if (count % 5 == 0)
            printf("\n");
        }
    }
    return 0;
}
```

## 分解质因数

> 将一个正整数分解质因数。例如：输入 90,打印出 90=2\*3\*3\*5。

- 程序分析：  
  对 n 进行分解质因数，应先找到一个最小的质数 k，然后按下述步骤完成：

  1、如果这个质数恰等于（小于的时候，继续执行循环）n，则说明分解质因数的过程已经结束，另外 打印出即可。

  2、但 n 能被 k 整除，则应打印出 k 的值，并用 n 除以 k 的商,作为新的正整数 n.重复执行第二步。

  3、如果 n 不能被 k 整除，则用 k+1 作为 k 的值,重复执行第一步。

```c
#include<stdio.h>
int main()
{
    int n,i;
    printf("请输入整数：");
    scanf("%d",&n);
    printf("%d=",n);
    for(i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            printf("%d",i);
            n/=i;
            if(n!=1) printf("*");
        }
    }

    printf("\n");
    return 0;
}
```

## 字符统计

> 输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。

- 程序分析：  
  利用 while 语句,条件为输入的字符不为'\n'。

```c
#include<stdio.h>
int main()
{
    char c;
    int letters=0,spaces=0,digits=0,others=0;
    printf("请输入一些字母：\n");
    while((c=getchar())!='\n')
    {
        if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            letters++;
        else if(c>='0'&&c<='9')
            digits++;
        else if(c==' ')
            spaces++;
        else
            others++;
    }
    printf("字母=%d,数字=%d,空格=%d,其他=%d\n",letters,digits,spaces,others);
    return 0;
}
```

## 求值

> 求 s=a+aa+aaa+aaaa+aa...a 的值，其中 a 是一个数字。例如 2+22+222+2222+22222(此时共有 5 个数相加)，几个数相加有键盘控制。

- 程序分析：  
  关键是计算出每一项的值。

```c
<stdio.h>
int main()
{
    int s=0,a,n,t;
    printf("请输入 a 和 n：\n");
    scanf("%d%d",&a,&n);
    t=a;
    while(n>0)
    {
        s+=t;
        a=a*10;
        t+=a;
        n--;
    }
    printf("a+aa+...=%d\n",s);
    return 0;
}
```

## 小球下落

> 一球从 100 米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第 10 次落地时，共经过多少米？第 10 次反弹多高？

```c
#include<stdio.h>
int main()
{
    float h,s;
    h=s=100;
    h=h/2; //第一次反弹高度
    for(int i=2;i<=10;i++)
    {
        s=s+2*h;
        h=h/2;
    }
    printf("第10次落地时，共经过%f米，第10次反弹高%f米\n",s,h);
    return 0;
}
```

## 打印菱形

> 打印出如下图案（菱形）。

```
   *
  ***
 *****
*******
 *****
  ***
   *
```

- 程序分析：  
  先把图形分成两部分来看待，前四行一个规律，后三行一个规律，利用双重 for 循环，第一层控制行，第二层控制列。

```c
#include <stdio.h>
int main()
{
    int i,j,k;
    for(i=0;i<=3;i++) {
        for(j=0;j<=2-i;j++) {
            printf(" ");
        }
        for(k=0;k<=2*i;k++) {
            printf("*");
        }
        printf("\n");
    }
    for(i=0;i<=2;i++) {
        for(j=0;j<=i;j++) {
            printf(" ");
        }
        for(k=0;k<=4-2*i;k++) {
            printf("*");
        }
        printf("\n");
    }
}
```

## 递推求和

> 有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前 20 项之和。

```c
#include <stdio.h>

int main()
{
    int i,t;
    float sum=0;
    float a=2,b=1;
    for(i=1;i<=20;i++)
    {
        sum=sum+a/b;
        t=a;
        a=a+b;
        b=t;
    }
    printf("%9.6f\n",sum);
}
```

## 累乘求和

> 求 1+2!+3!+...+20!的和。

```c
#include <stdio.h>

int main()
{
    int i;
    long double sum,mix;
    sum=0,mix=1;
    for(i=1;i<=20;i++)
    {
        mix=mix*i;
        sum=sum+mix;
    }
    printf("%Lf\n",sum);
}
```

## 递归求累乘

> 利用递归方法求 5!。

- 程序分析：  
  递归公式：fn=fn_1\*4!

```c
#include <stdio.h>

int main()
{
    int i;
    int fact(int);
    for(i=0;i<6;i++){
        printf("%d!=%d\n",i,fact(i));
    }
}
int fact(int j)
{
    int sum;
    if(j==0){
        sum=1;
    } else {
        sum=j*fact(j-1);
    }
    return sum;
}
```

## 数位求值

> 给一个不多于 5 位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。

```c
#include <stdio.h>

int main( )
{
    long a,b,c,d,e,x;
    printf("请输入 5 位数字：");
    scanf("%ld",&x);
    a=x/10000;        /*分解出万位*/
    b=x%10000/1000;   /*分解出千位*/
    c=x%1000/100;     /*分解出百位*/
    d=x%100/10;       /*分解出十位*/
    e=x%10;           /*分解出个位*/
    if (a!=0){
        printf("为 5 位数,逆序为： %ld %ld %ld %ld %ld\n",e,d,c,b,a);
    } else if(b!=0) {
         printf("为 4 位数,逆序为： %ld %ld %ld %ld\n",e,d,c,b);
    } else if(c!=0) {
         printf("为 3 位数,逆序为：%ld %ld %ld\n",e,d,c);
    } else if(d!=0) {
         printf("为 2 位数,逆序为： %ld %ld\n",e,d);
    } else if(e!=0) {
         printf("为 1 位数,逆序为：%ld\n",e);
    }
}
```

## 回文数

> 一个 5 位数，判断它是不是回文数。即 12321 是回文数，个位与万位相同，十位与千位相同。

- 程序分析：学会分解出每一位数。

```c
#include <stdio.h>

int main( )
{
    long ge,shi,qian,wan,x;
    printf("请输入 5 位数字：");
    scanf("%ld",&x);
    wan=x/10000;        /*分解出万位*/
    qian=x%10000/1000;  /*分解出千位*/
    shi=x%100/10;       /*分解出十位*/
    ge=x%10;            /*分解出个位*/
    if (ge==wan&&shi==qian) { /*个位等于万位并且十位等于千位*/
        printf("这是回文数\n");
    } else {
        printf("这不是回文数\n");
    }
}
```

## 选择排序

> 利用选择法，对 10 个数进行排序。

- 程序分析：  
  即从后 9 个比较过程中，选择一个最小的与第一个元素交换， 下次类推，即用第二个元素与后 8 个进行比较，并进行交换。

```c
#include<stdio.h>
#define N 10
int main()
{
    int i,j,a[N],temp;
    printf("请输入 10 个数字：\n");
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    for(i=0;i<N-1;i++)
    {
        int min=i;
        for(j=i+1;j<N;j++)
            if(a[min]>a[j]) min=j;
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
    printf("排序结果是:\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
```

## 二维数组

> 求一个 3\*3 矩阵对角线元素之和

- 程序分析：  
  利用双重 for 循环控制输入二维数组，再将 a[i][i]累加后输出。

```c
#include<stdio.h>
#define N 3
int main()
{
    int i,j,a[N][N],sum=0;
    printf("请输入矩阵(3*3)：\n");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<N;i++)
        sum+=a[i][i];
    printf("对角线之和为：%d\n",sum);
    return 0;
}
```

## 逆序

> 将一个数组逆序输出。

- 程序分析：用第一个与最后一个交换。

```c
#include<stdio.h>
#define N 10
int main()
{
    int a[N]={0,1,2,3,4,5,6,7,8,9};
    int i,t;
    printf("原始数组是:\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    for(i=0;i<N/2;i++)
    {
        t=a[i];
        a[i]=a[N-1-i];
        a[N-1-i]=t;
    }
    printf("\n排序后的数组:\n");
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
```

## 报数退圈

> 有 n 个人围成一圈，顺序排号。从第一个人开始报数（从 1 到 3 报数），凡报到 3 的人退出圈子，问最后留下的是原来第几号的那位。

```c
#include <stdio.h>
void main()
{
    int num[50],n,*p,j,loop,i,m,k;
    printf("请输入这一圈人的数量:\n");
    scanf("%d",&n);
    p=num;
    //开始给这些人编号
    for (j=0;j<n;j++)
    {
        *(p+j)=j+1;
    }
    i=0;//i用于计数,即让指针后移
    m=0;//m记录退出圈子的人数
    k=0;//k报数1,2,3
    while(m<n-1)//当退出的人数不大于总人数时，即留下的人数至少是一个人
        //这句不能写成m<n,因为假设有8人，当退出了6人时，此时还是进行人数退出，即m++，
        //这时是7<8，剩下的一个人自己喊1，2,3那么他也就退出了，将不会有输出
    {
        if (*(p+i)!=0)//如果这个人的头上编号不是0就开始报数加1，这里采用的方法是报数为3的人头上编号重置为0
        {
            k++;
        }
        if (k==3)
        {    k=0;    //报数清零，即下一个人从1开始报数
            *(p+i)=0;//将报数为3的人编号重置为0
            m++;    //退出人数加1
        }
        i++;      //指针后移
        if (i==n)//这句很关键，如果到了队尾，就要使指针重新指向对头
            //并且它只能放在i++后面，因为只有i++了才有可能i==n
        {
            i=0;
        }


    }
    printf("现在剩下的人是:");
    for (loop=0;loop<n;loop++)
    {
        if (num[loop]!=0)
        {
            printf("%2d号\n",num[loop]);
        }
    }

}
```

## 求值

> 809*??=800*??+9*?? 其中??代表的两位数, 809*??为四位数，8*??的结果为两位数，9*??的结果为 3 位数。求??代表的两位数，及 809\*??后的结果。

```c
#include <stdio.h>

void output(long int b, long int i){
    printf("\n%ld = 800 * %ld + 9 * %ld\n", b,i,i);
}


int main(){

    void output(long int b, long int i);
    long int a,b,i;
    a = 809;
    for(i = 10; i < 100; i++){
        b = i * a;
        if (b >= 1000 && b <= 10000 && 8 * i < 100 && 9 * i >= 100){
            output(b, i);
        }
    }
    return 0;
}
```

## 韩信点兵

> 相传韩信才智过人，从不直接清点自己军队的人数，只要让士兵先后以三人一排、五人一排、七人一排地变换队形，而他每次只掠一眼队伍的排尾就知道总人数了。输入 3 个非负整数 a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7），输出总人数的最小值（或报告无解）。已知总人数不小于 10，不超过 100 。

- 输入  
  输入 3 个非负整数 a,b,c ，表示每种队形排尾的人数（a<3,b<5,c<7）。例如,输入：2 4 5
- 输出  
  输出总人数的最小值（或报告无解，即输出 No answer）。实例，输出：89

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    int i;

    scanf("%d%d%d",&a,&b,&c);

    for(i=10;i<=100;i++){
        if(i%3==a && i%5==b && i%7==c){
            printf("%d\n",i);
            break;
        }
    }

    if(i==101)
        printf("No answer\n");


    return 0;
}
```

## 兰州烧饼

> 烧饼有两面，要做好一个兰州烧饼，要两面都弄热。当然，一次只能弄一个的话，效率就太低了。有这么一个大平底锅，一次可以同时放入 k 个兰州烧饼，一分钟能做好一面。而现在有 n 个兰州烧饼，至少需要多少分钟才能全部做好呢？

- 输入  
  依次输入 n 和 k，中间以空格分隔，其中 1 <= k,n <= 100000
- 输出  
  输出全部做好至少需要的分钟数
- 提示  
  如样例，三个兰州烧饼编号 a,b,c，首先 a 和 b，然后 a 和 c，最后 b 和 c，3 分钟完成

```c
#include <stdio.h>

int main(){
    int n;
    int k;
    int total;
    int result;

    while(scanf("%d%d",&n,&k)!=EOF){
        total=n*2;

        if(total<k){  //没有考虑到total<k的情况
            printf("2\n");
            continue;
        }

        result=total/k;

        if(total%k!=0)
            result++;

        printf("%d\n",result);
    }

    return 0;
}
```

## 进制转换

> 输入一个十进制数 N，将它转换成 R 进制数输出。

- 输入  
  输入数据包含多个测试实例，每个测试实例包含两个整数 N(32 位整数)和 R（2<=R<=16, R<>10）。
- 输出  
  为每个测试实例输出转换后的数，每个输出占一行。如果 R 大于 10，则对应的数字规则参考 16 进制（比如，10 用 A 表示，等等）。

```c
#include <stdio.h>

int main(){
    int number;
    int system;
    char s[50];
    int i;
    int length;
    int flag;

    while((scanf("%d%d",&number,&system))!=EOF){
        i=0;
        flag=0;

        if(number<0){
            number=-number;
            flag=1;
        }

        while(number){
            if(number%system<=9){
                s[i]=(number%system)+'0';
            }

            else if(number%system==10)
                s[i]='A';

            else if(number%system==11)
                s[i]='B';

            else if(number%system==12)
                s[i]='C';

            else if(number%system==13)
                s[i]='D';

            else if(number%system==14)
                s[i]='E';

            else if(number%system==15)
                s[i]='F';

            number/=system;
            i++;
        }
        length=i;

        if(flag==1)
            printf("-");

        for(i=length-1;i>=0;i--)
            printf("%c",s[i]);

        printf("\n");



    }


    return 0;
}
```

## 第几天？

> 给定一个日期，输出这个日期是该年的第几天。

- 输入  
  输入数据有多组，每组占一行，数据格式为 YYYY/MM/DD 组成，具体参见 sample input ,另外，可以向你确保所有的输入数据是合法的。
- 输出  
  对于每组输入数据，输出一行，表示该日期是该年的第几天。

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int c;
    int i;
    int day[13];
    int sum;

    day[1]=31;
    day[2]=28;
    day[3]=31;
    day[4]=30;
    day[5]=31;
    day[6]=30;
    day[7]=31;
    day[8]=31;
    day[9]=30;
    day[10]=31;
    day[11]=30;
    day[12]=31;

    while((scanf("%d/%d/%d",&a,&b,&c))!=EOF){
        sum=0;

        for(i=1;i<=b-1;i++)
            sum+=day[i];

        sum+=c;

        if((a%400==0 || (a%4==0 && a%100!=0)) && b>=3)
            sum++;

        printf("%d\n",sum);
    }


    return 0;
}
```

## 成绩转换

> 输入一个百分制的成绩 M，将其转换成对应的等级，具体转换规则如下：

90~100 为 A;
80~89 为 B;
70~79 为 C;
60~69 为 D;
0~59 为 E;

```c
#include <stdio.h>

int main(){
    int T;
    int n;
    char c;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        if(n>=90)
            c='A';

        else if(n>=80)
            c='B';

        else if(n>=70)
            c='C';

        else if(n>=60)
            c='D';

        else
            c='E';

        printf("%c\n",c);
    }
    return 0;
}
```

## 求实数的绝对值。

> 求实数的绝对值。

- 输入  
  输入数据有多组，每组占一行，每行包含一个实数。
- 输出  
  对于每组输入数据，输出它的绝对值，要求每组数据输出一行，结果保留两位小数。

```c
#include <stdio.h>

int main(){
    double number;

    while((scanf("%lf",&number)!=EOF)){
        if(number<0)
            number=-number;

        printf("%.2lf\n",number);
    }
    return 0;
}
```

## 计算球体积

> 根据输入的半径值，计算球的体积。

- 输入  
  输入数据有多组，每组占一行，每行包括一个实数，表示球的半径。
- 输出  
  输出对应的球的体积，对于每组输入数据，输出一行，计算结果保留三位小数。

```c
#include <stdio.h>
#define PI 3.1415927

int main(){
    double r;
    double result;

    while((scanf("%lf",&r))!=EOF){
        result=4.0*PI*r*r*r/3.0;

        printf("%.3lf\n",result);
    }

    return 0;
}
```

## 两点距离

> 输入两点坐标（X1,Y1）,（X2,Y2）(0<=x1,x2,y1,y2<=1000),计算并输出两点间的距离。

- 输入  
  第一行输入一个整数 n（0<n<=1000）,表示有 n 组测试数据;随后每组占一行，由 4 个实数组成，分别表示 x1,y1,x2,y2,数据之间用空格隔开。
- 输出  
  对于每组输入数据，输出一行，结果保留两位小数。

```c
#include <stdio.h>
#include <math.h>

int main(){
    int T;
    double a;
    double b;
    double c;
    double d;
    double distance;

    scanf("%d",&T);

    while(T--){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);

        distance=sqrt((a-c)*(a-c)+(b-d)*(b-d));

        printf("%.2lf\n",distance);
    }
    return 0;
}
```

## ASCII 码排序

> 输入三个字符（可以重复）后，按各字符的 ASCII 码从小到大的顺序输出这三个字符。

- 输入  
  第一行输入一个数 N,表示有 N 组测试数据。后面的 N 行输入多组数据，每组输入数据都是占一行，有三个字符组成，之间无空格。
- 输出  
  对于每组输入数据，输出一行，字符中间用一个空格分开。

```c
#include <stdio.h>

int main(){
    char a;
    char b;
    char c;
    char temp;
    int T;

    scanf("%d",&T);
    getchar();

    while(T--){
        scanf("%c%c%c",&a,&b,&c);
        getchar();

        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }

        if(a>c){
            temp=a;
            a=c;
            c=temp;
        }

        if(b>c){
            temp=b;
            b=c;
            c=temp;
        }

        printf("%c %c %c\n",a,b,c);
    }
    return 0;
}
```

## 数值统计

> 统计给定的 n 个数中，负数、零和正数的个数。

- 输入  
  输入数据有多组，每组占一行，每行的第一个数是整数 n（n<100），表示需要统计的数值的个数，然后是 n 个实数；如果 n=0，则表示输入结束，该行不做处理。
- 输出  
  对于每组输入数据，输出一行 a,b 和 c，分别表示给定的数据中负数、零和正数的个数。

```c
#include <stdio.h>

int main(){
    int n;
    int i;
    int a;
    int b;
    int c;
    double number;

    while(1){
        a=0;
        b=0;
        c=0;
        scanf("%d",&n);

        if(n==0)
            break;

        for(i=0;i<n;i++){
            scanf("%lf",&number);

            if(number<0)
                a++;

            else if(number==0)
                b++;

            else
                c++;
        }

        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
```

## 最小公倍数

> 给定两个正整数，计算这两个数的最小公倍数。

- 输入  
  输入包含多组测试数据，每组只有一行，包括两个不大于 1000 的正整数.
- 输出  
  对于每个测试用例，给出这两个数的最小公倍数，每个实例输出一行。

```c
#include <stdio.h>

int get_LCM(int a,int b);

int main(){
    int a;
    int b;

    while((scanf("%d%d",&a,&b))!=EOF){
        printf("%d\n",get_LCM(a,b));
    }

    return 0;
}

int get_LCM(int a,int b){
    int temp;
    int remainder;
    int A;
    int B;

    A=a;
    B=b;

    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }

    while(a%b){
        remainder=a%b;
        a=b;
        b=remainder;
    }

    return A*B/b;
}
```

## 公约数和公倍数

> 小明被一个问题给难住了，现在需要你帮帮忙。问题是：给出两个正整数，求出它们的最大公约数和最小公倍数。

- 输入  
  第一行输入一个整数 n（0<n<=10000)，表示有 n 组测试数据;随后的 n 行输入两个整数 i,j（0<i,j<=32767)。
- 输出  
  输出每组测试数据的最大公约数和最小公倍数

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int temp;
    int T;
    int a_save;
    int b_save;

    scanf("%d",&T);

    while(T--){
        scanf("%d%d",&a,&b);

        if(a<b){
            temp=a;
            a=b;
            b=temp;
        }

        a_save=a;
        b_save=b;
        while(a%b!=0){
            temp=a%b;
            a=b;
            b=temp;
        }

        printf("%d %d\n",b,a_save*b_save/b);
    }
    return 0;
}
```

## 5 个数求最值

> 设计一个从 5 个整数中取最小数和最大数的程序

- 输入  
  输入只有一组测试数据，为五个不大于 1 万的正整数
- 输出  
  输出两个数，第一个为这五个数中的最小值，第二个为这五个数中的最大值，两个数字以空格格开。

```c
#include <stdio.h>

int main(){
    int number;
    int min;
    int max;
    int i;

    for(i=0;i<5;i++){
        scanf("%d",&number);

        if(i==0){
            min=number;
            max=number;
            continue;
        }

        if(number<min)
            min=number;

        if(number>max)
            max=number;
    }

    printf("%d %d\n",min,max);

    return 0;
}
```

## 素数筛子算法

> 现在给你一个正整数 N，要你快速的找出在 2.....N 这些数里面所有的素数。

- 输入  
  给出一个正整数数 N(N<=2000000)、但 N 为 0 时结束程序。、测试数据不超过 100 组
- 输出  
  将 2~N 范围内所有的素数输出。两个数之间用空格隔开

```c
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 2000001

int main(){
    int i;
    int j;
    char flag[N];
    memset(flag,'0',N);
    flag[0]='1';
    flag[1]='1';

    for(i=2;i<=sqrt(N);i++){
        if(flag[i]=='0'){
            for(j=i*i;j<N;j+=i){
                flag[j]='1';
            }
        }
    }

    int number;

    while(1){
        scanf("%d",&number);

        if(number==0)
            break;

        for(i=2;i<=number;i++){
            if(flag[i]=='0')
                printf("%d ",i);
        }

        printf("\n");
    }

    return 0;
}
```

## 分数加减法

> 编写一个 C 程序，实现两个分数的加减法

- 输入  
  输入包含多行数据
  每行数据是一个字符串，格式是"a/boc/d"。
  其中 a, b, c, d 是一个 0-9 的整数。o 是运算符"+"或者"-"。
  数据以 EOF 结束
  输入数据保证合法

- 输出  
  对于输入数据的每一行输出两个分数的运算结果。 注意结果应符合书写习惯，没有多余的符号、分子、分母，并且化简至最简分数

```c
#include <stdio.h>

int gcd(int a,int b);

int main(){
    int a;
    int b;
    int c;
    int d;
    char sign;
    int fenmu;
    int fenzi;
    char temp;

    while(scanf("%d/%d%c%d/%d",&a,&b,&sign,&c,&d)!=EOF){
        fenmu=b*d/gcd(b,d);

        if(sign=='+')
            fenzi=a*fenmu/b+c*fenmu/d;

        else
            fenzi=a*fenmu/b-c*fenmu/d;

        if(fenzi==0){  //分子为0直接输出0
            printf("0\n");
            continue;
        }

        temp='+';
        if(fenzi<0){  //当为负数时，化为正数，标记负号
            fenzi=-fenzi;
            temp='-';
        }

        if(temp=='-')  //有负号时输出负号
            printf("-");

        if(fenzi%fenmu==0)  //如果整除时直接输出商
            printf("%d\n",fenzi/fenmu);

        else   //不整除时以分数的形式输出
            printf("%d/%d\n",fenzi/gcd(fenmu,fenzi),fenmu/gcd(fenmu,fenzi));
    }
    return 0;
}

int gcd(int a,int b){
    int temp;

    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }

    while(a%b!=0){
        temp=a%b;
        a=b;
        b=temp;
    }

    return b;
}
```

## 第二小整数

> 求 n 个整数中倒数第二小的数。每一个整数都独立看成一个数，比如，有三个数分别是 1，1，3，那么，第二小的数就是 1。

- 输入  
  输入包含多组测试数据。
  输入的第一行是一个整数 C，表示有 C 测试数据；
  每组测试数据的第一行是一个整数 n，表示本组测试数据有 n 个整数（2<=n<=10），接着一行是 n 个整数 (每个数均小于 100);

- 输出  
  请为每组测试数据输出第二小的整数，每组输出占一行。

```c
#include <stdio.h>

int main(){
    int T;
    int n;
    int i;
    int min;
    int min_flag;
    int number[11];

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        for(i=0;i<n;i++){
            scanf("%d",&number[i]);

            if(i==0){
                min=number[0];
                min_flag=0;
            }

            if(number[i]<min){
                min=number[i];
                min_flag=i;
            }
        }

        for(i=0;i<n;i++){
            if(i!=min_flag){
                min=number[i];
                break;
            }
        }

        for(i=0;i<n;i++){
            if(i!=min_flag && number[i]<min)
                min=number[i];
        }

        printf("%d\n",min);
    }

    return 0;
}
```

## 奇偶数分离

> 有一个整型偶数 n(2<= n <=10000),你要做的是：先把 1 到 n 中的所有奇数从小到大输出，再把所有的偶数从小到大输出。

- 输入  
  第一行有一个整数 i（2<=i<30)表示有 i 组测试数据；每组有一个整型偶数 n。
- 输出  
  第一行输出所有的奇数。第二行输出所有的偶数

```c
#include <stdio.h>

int main(){
    int T;
    int i;
    int n;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            if(i%2==1){
                if(i==1)
                    printf("%d",i);

                else
                    printf(" %d",i);
            }
        }

        printf("\n");

        for(i=1;i<=n;i++){
            if(i%2==0){
                if(i==2)
                    printf("%d",i);

                else
                    printf(" %d",i);
            }
        }

        printf("\n");

        if(T!=0)
            printf("\n");
    }

    return 0;
}
```

## 奇偶位互换

> 给定一个长度为偶数位的 0,1 字符串，请编程实现串的奇偶位互换。

- 输入  
  输入包含多组测试数据；
  输入的第一行是一个整数 C，表示有 C 测试数据；
  接下来是 C 组测试数据，每组数据输入均为 0,1 字符串，保证串长为偶数位(串长<=50)。

- 输出  
  请为每组测试数据输出奇偶位互换后的结果；每组输出占一行。

```c
#include <stdio.h>
#include <string.h>

int main(){
    int T;
    char s[51];
    int length;
    char temp;
    int i;

    scanf("%d",&T);

    while(T--){
        scanf("%s",s);
        length=strlen(s);

        for(i=0;i<length-1;i+=2){
            temp=s[i];
            s[i]=s[i+1];
            s[i+1]=temp;
        }

        printf("%s\n",s);
    }

    return 0;
}
```

## 统计硬币

> 假设一堆由 1 分、2 分、5 分组成的 n 个硬币总面值为 m 分，求一共有多少种可能的组合方式（某种面值的硬币可以数量可以为 0）。

- 输入  
  输入数据第一行有一个正整数 T，表示有 T 组测试数据；接下来的 T 行，每行有两个数 n,m，n 和 m 的含义同上。
- 输出  
  对于每组测试数据，请输出可能的组合方式数；每组输出占一行。

```c
#include <stdio.h>

int main(){
    int T;
    int amount;
    int sum;
    int one_amount;
    int two_amount;
    int five_amount;
    int a;
    int b;
    int c;
    int result;

    scanf("%d",&T);

    while(T--){
        result=0;
        scanf("%d%d",&amount,&sum);
        one_amount=sum/1;
        two_amount=sum/2;
        five_amount=sum/5;

        for(a=0;a<=one_amount;a++){
            for(b=0;b<=two_amount;b++){
                for(c=0;c<=five_amount;c++){
                    if((a+b+c)==amount && (a*1+b*2+c*5)==sum)
                        result++;
                }
            }
        }
        printf("%d\n",result);
    }

    return 0;
}
```

## 汉字统计

> 统计给定文本文件中汉字的个数。

- 输入  
  输入文件首先包含一个整数 n，表示测试实例的个数，然后是 n 段文本。
- 输出  
  对于每一段文本，输出其中的汉字的个数，每个测试实例的输出占一行。

```c
#include <stdio.h>

int main(){
    int T;
    char c;
    int amount;

    scanf("%d",&T);
    getchar();

    while(T--){
        amount=0;
        while((c=getchar())!='\n'){
            if(c<0 || c>127)
                amount++;
        }
        printf("%d\n",amount/2);
    }


    return 0;
}
```

## 偶数求和

> 有一个长度为 n(n<=100)的数列，该数列定义为从 2 开始的递增有序偶数，现在要求你按照顺序每 m 个数求出一个平均值，如果最后不足 m 个，则以实际数量求平均值。编程输出该平均值序列。

- 输入  
  输入数据有多组，每组占一行，包含两个正整数 n 和 m，n 和 m 的含义如上所述。
- 输出  
  对于每组输入数据，输出一个平均值序列，每组输出占一行。

```c
#include <stdio.h>

int main(){
    int sequence[101];
    int i;
    int j;
    int n;
    int m;
    int result;
    int remainder;
    int flag;

    for(i=0;i<101;i++)
        sequence[i]=(i+1)*2;

    while((scanf("%d%d",&n,&m))!=EOF){
        result=0;
        j=1;
        flag=0;

        remainder=n%m;

        for(i=0;i<=n;i++){
            if(j<=m){
                result+=sequence[i];
            }

            else{
                if(flag==0)
                    printf("%d",result/m);

                else
                    printf(" %d",result/m);

                flag=1;
                j=1;
                result=sequence[i];
            }
            j++;
        }

        if(remainder){
            printf(" %d",(result-sequence[n])/remainder);
        }

        printf("\n");
    }




    return 0;
}
```

## 杨辉三角

> 还记得中学时候学过的杨辉三角吗？具体的定义这里不再描述，你可以参考以下的图形：

```
  1
  1 1
  1 2 1
  1 3 3 1
  1 4 6 4 1
  1 5 10 10 5 1
```

- 输入  
  输入数据包含多个测试实例，每个测试实例的输入只包含一个正整数 n（1<=n<=30），表示将要输出的杨辉三角的层数。
- 输出  
  对应于每一个输入，请输出相应层数的杨辉三角，每一层的整数之间用一个空格隔开，每一个杨辉三角后面加一个空行。

```c
#include <stdio.h>   //本来不会做的，但是编着编着就出来了，么么哒

int main(){
    int n;
    int triangle[31][31];
    int i;
    int j;

    while((scanf("%d",&n))!=EOF){
        for(i=0;i<31;i++)
            for(j=0;j<31;j++)
                triangle[i][j]=0;

        triangle[0][0]=1;
        triangle[1][0]=1;
        triangle[1][1]=1;

        for(i=2;i<n;i++){
            triangle[i][0]=1;
            triangle[i][i]=1;
            for(j=1;j<=i;j++){
                triangle[i][j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
        }

        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(triangle[i][j]!=0){
                    if(j==0)
                        printf("%d",triangle[i][j]);

                    else
                        printf(" %d",triangle[i][j]);
                }
            }

            printf("\n");
        }

        printf("\n");

    }
    return 0;
}
```

## 统计字符

> 统计一个给定字符串中指定的字符出现的次数

- 输入  
  测试输入包含若干测试用例，每个测试用例包含 2 行，第 1 行为一个长度不超过 5 的字符串，第 2 行为一个长度不超过 80 的字符串。注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。当读到'#'时输入结束，相应的结果不要输出。
- 输出  
  对每个测试用例，统计第 1 行中字符串的每个字符在第 2 行字符串中出现的次数，按如下格式输出：
  c0 n0
  c1 n1
  c2 n2
  ...
  其中 ci 是第 1 行中第 i 个字符，ni 是 ci 出现的次数。

```c
#include <stdio.h>
#include <string.h>

int main(){
    char s1[6];
    char s2[81];
    int s1_length;
    int s2_length;
    int i;
    int j;
    int time;
    char c;

    while(1){
        i=0;    //s1包含空格
        while((c=getchar())!='\n'){
            s1[i]=c;
            i++;
        }
        s1[i]='\0';

        if(s1[0]=='#')
            break;

        i=0;    //s2包含空格
        while((c=getchar())!='\n'){
            s2[i]=c;
            i++;
        }
        s2[i]='\0';

        s1_length=strlen(s1);
        s2_length=strlen(s2);

        for(i=0;i<s1_length;i++){
            time=0;
            for(j=0;j<s2_length;j++){
                if(s1[i]==s2[j])
                    time++;
            }

            printf("%c %d\n",s1[i],time);
        }
    }
    return 0;
}
```

## 完数

> 完数的定义：如果一个大于 1 的正整数的所有因子之和等于它的本身，则称这个数是完数，比如 6，28 都是完数：6=1+2+3；28=1+2+4+7+14。

- 输入  
  输入数据包含多行，第一行是一个正整数 n，表示测试实例的个数，然后就是 n 个测试实例，每个实例占一行，由两个正整数 num1 和 num2 组成,(1<num1,num2<10000) 。
- 输出  
  对于每组测试数据，请输出 num1 和 num2 之间（包括 num1 和 num2）存在的完数个数。

```c
#include <stdio.h>

int if_perfect_number(int number);

int main(){
    int T;
    int number1;
    int number2;
    int temp;
    int i;
    int amount;

    scanf("%d",&T);

    while(T--){
        amount=0;
        scanf("%d%d",&number1,&number2);

        if(number1>number2){
            temp=number1;
            number1=number2;
            number2=temp;
        }

        for(i=number1;i<=number2;i++){
            if(if_perfect_number(i)==1)
                amount++;
        }

        printf("%d\n",amount);
    }
    return 0;
}

int if_perfect_number(int number){
    int i;
    int sum;

    sum=0;

    for(i=1;i<=number/2;i++){
        if(number%i==0)
            sum+=i;
    }

    if(sum==number)
        return 1;

    else
        return 0;
}
```

## 素数回文

> xiaoou33 对既是素数又是回文的数特别感兴趣。比如说 151 既是素数又是个回文。现在 xiaoou333 想要你帮助他找出某个范围内的素数回文数，请你写个程序找出 a 跟 b 之间满足条件的数。(5 <= a < b <= 100,000,000);

- 输入  
  这里有许多组数据，每组包括两组数据 a 跟 b。
- 输出  
  对每一组数据,按从小到大输出 a，b 之间所有满足条件的素数回文数（包括 a 跟 b）每组数据之后空一行。

```c
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 10000000   //9999999是题目要求范围的最大回文数
char flag[N];

int palindrome_number(int number);

int main(){
    int i;
    int j;
    int a;
    int b;

    memset(flag,'0',N);
    flag[0]='1';
    flag[1]='1';

    for(i=2;i<=sqrt((double)N);i++){
        if(flag[i]=='0'){
            for(j=i*i;j<N;j+=i)
                flag[j]='1';
        }
    }

    while(scanf("%d%d",&a,&b)!=EOF){
        for(i=a;i<=b;i++){
            if(i>N-1)
                continue;

            if(palindrome_number(i)==1 && flag[i]=='0')
                printf("%d\n",i);
        }

        printf("\n");
    }

    return 0;
}

int palindrome_number(int number){
    int array[9];
    int i;
    int length;
    int flag;

    i=0;
    while(number){
        array[i]=number%10;
        i++;
        number/=10;
    }
    length=i;

    flag=0;
    for(i=0;i<length/2;i++){
        if(array[i]!=array[length-i-1]){
            flag=1;
            break;
        }
    }

    if(flag==1)
        return 0;

    else
        return 1;
}
```

## 快速排序

> 给你 n 个整数，请按从大到小的顺序输出其中前 m 大的数。

- 输入  
  每组测试数据有两行，第一行有两个数 n,m(0<n,m<1000000)，第二行包含 n 个各不相同，且都处于区间[-500000,500000]的整数。
- 输出  
  对每组测试数据按从大到小的顺序输出前 m 大的数。

```c
#include <stdio.h>

void quickSort(int a[],int left,int right);
int array[1000001];

int main(){
    int n;
    int m;
    int i;

    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&array[i]);

        quickSort(array,0,n-1);

        for(i=n-1;i>n-m-1;i--){
            if(i==n-1)
                printf("%d",array[i]);

            else
                printf(" %d",array[i]);
        }

        printf("\n");
    }

    return 0;
}

void quickSort(int a[],int left,int right){
    int i;
    int j;
    int temp;

    i=left;
    j=right;
    temp=a[left];

    if(left>=right)
        return;

    while(i!=j){
        while(i<j && a[j]>=temp)
            j--;

        if(i<j){
            a[i]=a[j];
        }


        while(i<j && a[i]<=temp)
             i++;

        if(i<j){
            a[j]=a[i];
        }
    }
    a[i]=temp;

    quickSort(a,left,i-1);
    quickSort(a,i+1,right);
}
```

## 开门人和关门人

> 每天第一个到机房的人要把门打开，最后一个离开的人要把门关好。现有一堆杂乱的机房签

到、签离记录，请根据记录找出当天开门和关门的人。

- 输入  
  测试输入的第一行给出记录的总天数 N ( > 0 )。下面列出了 N 天的记录。
  每天的记录在第一行给出记录的条目数 M ( > 0 )，下面是 M 行，每行的格式为

证件号码 签到时间 签离时间

其中时间按“小时:分钟:秒钟”（各占 2 位）给出，证件号码是长度不超过 15 的字符串。

- 输出  
  对每一天的记录输出 1 行，即当天开门和关门人的证件号码，中间用 1 空格分隔。
  注意：在裁判的标准测试输入中，所有记录保证完整，每个人的签到时间在签离时间之前，
  且没有多人同时签到或者签离的情况。

```c
#include <stdio.h>
#include <string.h>

int main(){
    int N;
    int M;
    int i;
    char ID[16];
    char minID[16];
    char maxID[16];
    char s1[9];
    char s2[9];
    char time1[7];
    char time2[7];
    char minTime[7];
    char maxTime[7];

    scanf("%d",&N);

    while(N--){
        scanf("%d",&M);

        for(i=0;i<M;i++){
            scanf("%s%s%s",ID,s1,s2);
            time1[0]=s1[0];
            time1[1]=s1[1];
            time1[2]=s1[3];
            time1[3]=s1[4];
            time1[4]=s1[6];
            time1[5]=s1[7];
            time1[6]='\0';

            time2[0]=s2[0];
            time2[1]=s2[1];
            time2[2]=s2[3];
            time2[3]=s2[4];
            time2[4]=s2[6];
            time2[5]=s2[7];
            time2[6]='\0';

            if(i==0){
                strcpy(minID,ID);
                strcpy(maxID,ID);
                strcpy(minTime,time1);
                strcpy(maxTime,time2);
                continue;
            }

            if(strcmp(time1,minTime)<0){
                strcpy(minID,ID);
                strcpy(minTime,time1);
            }

            if(strcmp(time2,maxTime)>0){
                strcpy(maxID,ID);
                strcpy(maxTime,time2);
            }
        }

        printf("%s %s\n",minID,maxID);


    }


    return 0;
}
```

## 鸡兔同笼

> 已知鸡和兔的总数量为 n,总腿数为 m。输入 n 和 m,依次输出鸡和兔的数目，如果无解，则输出“No answer”(不要引号)。

- 输入  
  第一行输入一个数据 a,代表接下来共有几组数据，在接下来的(a<10)、a 行里，每行都有一个 n 和 m.(0<m,n<100)
- 输出  
  输出鸡兔的个数，或者 No answer

```c
#include <stdio.h>

int main(){
    int T;
    int n;
    int m;

    scanf("%d",&T);

    while(T--){
        scanf("%d%d",&n,&m);

        if((m-2*n)>=0 && (m-2*n)%2==0 && (4*n-m)>=0 && (4*n-m)%2==0)
            printf("%d %d\n",(4*n-m)/2,(m-2*n)/2);

        else
            printf("No answer\n");
    }
    return 0;
}
```

## 日期计算

> 如题，输入一个日期，格式如：2010 10 24 ，判断这一天是这一年中的第几天。

- 输入  
  第一行输入一个数 N（0<N<=100）,表示有 N 组测试数据。后面的 N 行输入多组输入数据，每行的输入数据都是一个按题目要求格式输入的日期。
- 输出  
  每组输入数据的输出占一行，输出判断出的天数 n

```c
#include <stdio.h>

int main(){
    int T;
    int a;
    int b;
    int c;
    int i;
    int day[13];
    int amount;

    day[1]=31;
    day[2]=28;
    day[3]=31;
    day[4]=30;
    day[5]=31;
    day[6]=30;
    day[7]=31;
    day[8]=31;
    day[9]=30;
    day[10]=31;
    day[11]=30;
    day[12]=31;

    scanf("%d",&T);

    while(T--){
        scanf("%d%d%d",&a,&b,&c);

        amount=0;
        for(i=1;i<b;i++)
            amount+=day[i];
        amount+=c;

        if((a%400==0 || (a%4==0 && a%100!=0)) && i>=3)
            amount++;

        printf("%d\n",amount);
    }
    return 0;
}
```

## 开灯问题

> 有 n 盏灯，编号为 1~n，第 1 个人把所有灯打开，第 2 个人按下所有编号为 2 的倍数的开关（这些灯将被关掉），第 3 个人按下所有编号为 3 的倍数的开关（其中关掉的灯将被打开，开着的灯将被关闭），依此类推。一共有 k 个人，问最后有哪些灯开着？输入：n 和 k，输出开着的灯编号。k≤n≤1000

- 输入  
  输入一组数据：n 和 k
- 输出  
  输出开着的灯编号

```c
#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int k;
    int flag[1001];
    int i;
    int j;

    scanf("%d%d",&n,&k);
    memset(flag,0,sizeof(int)*1001);

    for(i=1;i<=k;i++){
        for(j=1;j<=n;j++){
            if(j%i==0){
                if(flag[j-1]==0)
                    flag[j-1]=1;

                else
                    flag[j-1]=0;
            }
        }
    }

    for(i=0;i<n;i++){
        if(flag[i]==1){
            printf("%d",i+1);
            flag[i]=0;
            break;
        }
    }

    for(i=0;i<n;i++){
        if(flag[i]==1)
            printf(" %d",i+1);
    }

    printf("\n");

    return 0;
}
```

## 字符串替换

> 编写一个程序实现将字符串中的所有"you"替换成"we"

- 输入  
  输入包含多行数据
  每行数据是一个字符串，长度不超过 1000
  数据以 EOF 结束

- 输出  
  对于输入的每一行，输出替换后的字符串

```c
#include <stdio.h>
#include <string.h>

int main(){
    char c;
    char s[1001];
    int i;
    int length;

    while(scanf("%c",&c)!=EOF){
        i=0;
        while(c!='\n'){
            s[i]=c;
            i++;
            c=getchar();
        }
        s[i]='\0';
        length=strlen(s);

        for(i=0;i<length-2;i++){  //这里处理很巧妙，直接赋值即可，真是高
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u'){
                s[i]='w';
                s[i+1]='e';
                s[i+2]='\0';  //赋值为'\0'，是因为其他位置的字符不可能为'\0'
            }
        }

        for(i=0;i<length;i++){
            if(s[i]!='\0')
                printf("%c",s[i]);
        }

        printf("\n");
    }
    return 0;
}
```

## 字母统计

> 现在给你一个由小写字母组成字符串，要你找出字符串中出现次数最多的字母，如果出现次数最多字母有多个那么输出最小的那个。

- 输入  
  第一行输入一个正整数 T（0<T<25）随后 T 行输入一个字符串 s,s 长度小于 1010。
- 输出  
  每组数据输出占一行，输出出现次数最多的字符；

```c
#include <stdio.h>
#include <string.h>

int main(){
    char s[1100];
    int T;
    int amount[27];
    int i;
    int max;
    char c;

    scanf("%d",&T);

    while(T--){
        scanf("%s",&s);

        memset(amount,0,sizeof(int)*27);

        for(i=0;s[i]!='\0';i++){
            amount[s[i]-'a'+1]++;
        }

        for(i=1;i<=26;i++){
            if(amount[i]!=0){
                c=i-1+'a';
                max=amount[i];
                break;
            }
        }

        for(i=1;i<=26;i++){
            if(amount[i]>max){
                c=i-1+'a';
                max=amount[i];
            }
        }

        printf("%c\n",c);
    }
    return 0;
}
```

## 字符串逆序输出

> 给定一行字符，逆序输出此行（空格.数字不输出）

- 输入  
  第一行是一个整数 N(N<10)表示测试数据的组数）
  每组测试数据占一行，每行数据中间有且只有一个空格（这样你可以把此行当成两个字符串读取）。
  每行字符长度不超过 40
  并且保证输入的字符只有空格（1 个），数字，小写字母三种

- 输出  
  对应每行测试数据，逆序输出（空格和数字不输出）

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[50];
    int T;
    int length;
    int i;

    scanf("%d",&T);
    getchar();

    while(T--){
        gets(s);
        length=strlen(s);

        for(i=length-1;i>=0;i--){
            if(isalpha(s[i]))
                printf("%c",s[i]);
        }

        printf("\n");
    }
    return 0;
}
```

## 交换输出

> 输入 n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。(如果这个第一个数就是最小的数，则保持原样输出，如果最小的数有相同的按照前面的交换)

- 输入  
  输入数据有多组，每组占一行，每行的开始是一个整数 n，表示这个测试实例的数值的个数，跟着就是 n 个整数。n=0 表示输入的结束，不做处理。
- 输出  
  对于每组输入数据，输出交换后的数列，每组输出占一行。

```c
#include <stdio.h>

int main(){
    int n;
    int number[101];
    int i;
    int min;
    int flag;
    int temp;

    while(1){
        scanf("%d",&n);

        if(n==0)
            break;

        for(i=0;i<n;i++)
            scanf("%d",&number[i]);

        flag=0;
        min=number[0];

        for(i=0;i<n;i++){
            if(number[i]<min){
                min=number[i];
                flag=i;
            }
        }

        temp=number[0];
        number[0]=number[flag];
        number[flag]=temp;

        for(i=0;i<n;i++){
            if(i!=0)
                printf(" ");

            printf("%d",number[i]);
        }
        printf("\n");
    }
    return 0;
}
```

## 比较字母大小

> 任意给出两个英文字母，比较它们的大小，规定 26 个英文字母 A,B,C.....Z 依次从大到小。

- 输入  
  第一行输入 T，表示有 T 组数据；接下来有 T 行，每行有两个字母，以空格隔开；
- 输出  
  输出各组数据的比较结果，输出格式见样例输出；（注意输出严格按照输入的顺序即输入是 A B，输出时必须是 A?B）

```c
#include <stdio.h>

int main(){
    int T;
    char a;
    char b;
    char compare;

    scanf("%d",&T);
    getchar();

    while(T--){
        scanf("%c %c",&a,&b);
        getchar();

        if(a==b)
            compare='=';

        else if(a>b)
            compare='<';

        else
            compare='>';

        printf("%c%c%c\n",a,compare,b);
    }
    return 0;
}
```

## 猴子吃桃问题

> 有一堆桃子不知数目，猴子第一天吃掉一半，又多吃了一个，第二天照此方法，吃掉剩下桃子的一半又多一个，天天如此，到第 m 天早上，猴子发现只剩一只桃子了，问这堆桃子原来有多少个？ (m<29)

- 输入  
  第一行有一个整数 n,表示有 n 组测试数据（从第二行开始，每一行的数据为：第 m 天）；
- 输出  
  每一行数据是桃子的总个数

```c
#include <stdio.h>

int main(){
    int T;
    int m;
    int i;
    int result;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&m);

        result=1;
        for(i=1;i<=m;i++)
            result=(result+1)*2;

        printf("%d\n",result);
    }
    return 0;
}
```

## 九九乘法表

> 小时候学过的九九乘法表也许将会扎根于我们一生的记忆,现在让我们重温那些温暖的记忆,请编程输出九九乘法表.

现在要求你输出它的格式与平常的 不同啊! 是那种反过来的三角形啦，具体如下图：
每两个式子之前用一个空格 隔开。。。

- 输入  
  第一有一个整数 N，表示有 N 组数据（N<10）接下来由 N 行，每行只有一个整数 M(1<=M<=9);
- 输出  
  对应每个整数 M，根据要求输出乘法表的前 N 行,具体格式参见输入输出样例和上图.每两组测试数据结果之间有一个空行隔开，

```c
#include <stdio.h>
#include <math.h>

int main(){
    int T;
    int n;
    int i;
    int j;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&n);

        for(i=1;i<=n;i++){
            for(j=i;j<=9;j++){
                if(j!=i)
                    printf(" ");

                printf("%d*%d=%d",i,j,i*j);
            }
            printf("\n");
        }

        if(T!=0)
            printf("\n");
    }
    return 0;
}
```

## 16 进制的简单运算

> 现在给你一个 16 进制的加减法的表达式，要求用 8 进制输出表达式的结果。

- 输入  
  第一行输入一个正整数 T（0<T<100000）
  接下来有 T 行，每行输入一个字符串 s（长度小于 15)字符串中有两个数和一个加号或者一个减号，且表达式合法并且所有运算的数都小于 31 位

- 输出  
  每个表达式输出占一行，输出表达式 8 进制的结果。

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int sum;
    int T;
    char c;

    scanf("%d",&T);

    while(T--){
        scanf("%x%c%x",&a,&c,&b);

        if(c=='+')
            sum=a+b;

        else
            sum=a-b;

        if(sum<0){   //只有当sum为__int64类型时，才要进行正负的判断
            sum=-sum;
            printf("-");
        }

        printf("%o\n",sum);
    }



    return 0;
}
```

## 三角形面积

> 给你三个点，表示一个三角形的三个顶点，现你的任务是求出该三角形的面积

- 输入  
  每行是一组测试数据，有 6 个整数 x1,y1,x2,y2,x3,y3 分别表示三个点的横纵坐标。（坐标值都在 0 到 10000 之间）输入 0 0 0 0 0 0 表示输入结束。测试数据不超过 10000 组
- 输出  
  输出这三个点所代表的三角形的面积，结果精确到小数点后 1 位（即使是整数也要输出一位小数位）

```c
#include <stdio.h>
#include <math.h>

int main(){
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    double s;

    while(1){
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);

        if(x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0)
            break;

        s=fabs((double)x1*y2-x2*y1+x3*y1-x1*y3+x2*y3-x3*y2)/2;

        printf("%.1lf\n",s);
    }

    return 0;
}
```

## 平方和与立方和

> 给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。

- 输入  
  输入数据包含多组测试实例，每组测试实例包含一行，由两个整数 m 和 n 组成。
- 输出  
  对于每组输入数据，输出一行，应包括两个整数 x 和 y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。你可以认为 32 位整数足以保存结果。

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int i;
    int temp;
    int oushu_sum;
    int jishu_sum;

    while((scanf("%d%d",&a,&b))!=EOF){
        oushu_sum=0;
        jishu_sum=0;

        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }

        for(i=a;i<=b;i++){
            if(i%2==0){
                oushu_sum+=(i*i);
            }

            else
                jishu_sum+=(i*i*i);
        }

        printf("%d %d\n",oushu_sum,jishu_sum);
    }

    return 0;
}
```

## 水仙花数

> 春天是鲜花的季节，水仙花就是其中最迷人的代表，数学上有个水仙花数，他是这样定义的：  
> “水仙花数”是指一个三位数，它的各位数字的立方和等于其本身，比如：153=1^3+5^3+3^3。  
> 现在要求输出所有在 m 和 n 范围内的水仙花数。

- 输入  
  输入数据有多组，每组占一行，包括两个整数 m 和 n（100<=m<=n<=999）。
- 输出  
  对于每个测试实例，要求输出所有在给定范围内的水仙花数，就是说，输出的水仙花数必须大于等于 m,并且小于等于 n，如果有多个，则要求从小到大排列在一行内输出，之间用一个空格隔开;
  如果给定的范围内不存在水仙花数，则输出 no;
  每个测试实例的输出占一行。

```c
#include <stdio.h>

int main(){
    int a;
    int b;
    int temp;
    int i;

    int number1;
    int number2;
    int number3;
    int flag;

    while((scanf("%d%d",&a,&b))!=EOF){
        flag=0;
        if(a>b){
            temp=a;
            a=b;
            b=temp;
        }

        for(i=a;i<=b;i++){
            number1=i%10;
            number2=i/10%10;
            number3=i/100;

            if(i==(number1*number1*number1+number2*number2*number2+number3*number3*number3)){
                if(flag==0)
                    printf("%d",i);

                else
                    printf(" %d",i);
                flag=1;
            }
        }

        if(flag==0)
            printf("no");

        printf("\n");
    }

    return 0;
}
```

## 多项式求和

> 多项式的描述如下：
> 
> 1 - 1/2 + 1/3 - 1/4 + 1/5 - 1/6 + ...
> 
> 现在请你求出该多项式的前 n 项的和。

- 输入  
  输入数据由 2 行组成，首先是一个正整数 m（m<100），表示测试实例的个数，第二行包含 m 个正整数，对于每一个整数(不妨设为 n,n<1000），求该多项式的前 n 项的和。
- 输出  
  对于每个测试实例 n，要求输出多项式前 n 项的和。每个测试实例的输出占一行，结果保留 2 位小数。

```c
#include <stdio.h>

double get_result(int number);

int main(){
    int n;
    int number;

    scanf("%d",&n);

    while(n--){
        scanf("%d",&number);

        printf("%.2lf\n",get_result(number));
    }

    return 0;
}

double get_result(int number){
    int i;
    int temp=1;
    double result=0;

    for(i=1;i<=number;i++){
        result+=(1.0/i*temp);
        temp=-temp;
    }

    return result;
}
```

## 绝对值排序

> 输入 n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。

- 输入  
  输入数据有多组，每组占一行，每行的第一个数字为 n,接着是 n 个整数，n=0 表示输入数据的结束，不做处理
- 输出  
  对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。

```c
#include <stdio.h>
#include <math.h>

int main(){
    int n;
    int number[101];
    int i;
    int j;
    int temp;

    while(1){
        scanf("%d",&n);

        if(n==0)
            break;

        for(i=0;i<n;i++)
            scanf("%d",&number[i]);

        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(fabs(number[i])<(fabs(number[j]))){
                    temp=number[i];
                    number[i]=number[j];
                    number[j]=temp;
                }
            }
        }

        for(i=0;i<n;i++){
            printf("%d",number[i]);

            if(i!=n-1)
                printf(" ");
        }

        printf("\n");

    }


    return 0;
}
```

## 首字母变大写

> 输入一个英文句子，将每个单词的第一个字母改成大写字母。

- 输入  
  输入数据包含多个测试实例，每个测试实例是一个长度不超过 100 的英文句子，占一行。
- 输出  
  请输出按照要求改写后的英文句子。

```c
#include <stdio.h>
#include <ctype.h>

int main(){
    char c;
    int flag;

    while((scanf("%c",&c))!=EOF){
        flag=1;

        while(c!='\n'){
            if(islower(c)!=0 && flag==1){
                c=toupper(c);
                flag=0;
            }


            if(c==' ')
                flag=1;

            printf("%c",c);

            c=getchar();
        }

        printf("\n");
    }

    return 0;
}
```

## a/b + c/d

> 给你 2 个分数，求他们的和，并要求和为最简形式。

- 输入  
  输入首先包含一个正整数 T（T<=1000），表示有 T 组测试数据，然后是 T 行数据，每行包含四个正整数 a,b,c,d（0<a,b,c,d<1000），表示两个分数 a/b 和 c/d。
- 输出  
  对于每组测试数据，输出两个整数 e 和 f，表示 a/b + c/d 的最简化结果是 e/f，每组输出占一行。

```c
#include <stdio.h>

int get_gcd(int a,int b);

int main(){
    int T;
    int a;
    int b;
    int c;
    int d;
    int lcm;
    int temp;
    int gcd;

    scanf("%d",&T);

    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        lcm=b*d/get_gcd(b,d);

        temp=(lcm/b*a+lcm/d*c);
        gcd=get_gcd(temp,lcm);

        printf("%d %d\n",temp/gcd,lcm/gcd);
    }
    return 0;
}

int get_gcd(int a,int b){
    int temp;
    int remainder;

    if(a<b){
        temp=a;
        a=b;
        b=temp;
    }

    while(a%b){
        remainder=a%b;

        a=b;
        b=remainder;
    }

    return b;
}
```
