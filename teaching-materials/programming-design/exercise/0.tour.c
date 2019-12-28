
// 单行注释

/*
多行注释
line1
line2
*/

// 宏定义: #define <keyword>
// 按惯例大写，并不严格要求
#define DAYS_IN_YEAR 365

// 枚举常量也是一种宏定义的方式
// {}所有语句以逗号结束
enum days
{
  SUN = 1,
  MON,
  TUE,
  WED,
  THU,
  FRI,
  SAT
};
// MON 值为 2, TUE 值为 3.

// 引用头文件需要使用 #include
#include <stdlib.h>
#include <stdio.h> // printf scanf getchar
#include <math.h>  // sqrt exp log
#include <string.h>

// <>中的文件名来自于C标准库的头文件
// 如果是自定义的头文件需要用""代替<>
// #include "my_header.h"

// 程序的入口是一个名字为main的函数，其返回值是一个int型
int main(void)
{
  // your program
}

// 程序运行时的命令行参数，会从main的参数中传入
// agrc是参数的个数，程序名也会计入
// argv是一个字符串数组，包含了参数
// arg[0]是程序名，argv[1]是第一个参数
int main(int argc, char **argv)
{
  // 使用printf打印输出
  // %d是将参数以整形打印
  // \n表示一个换行
  printf("%d\n", 0); // => Prints 0

  ///////////////////////////////////////
  // 数据类型
  ///////////////////////////////////////

  // 整形 4 bytes
  int x_int = 0;

  // 短整型 2 bytes
  short x_short = 0;

  // 字符型 1 byte
  // ascii
  char x_char = 0;
  char y_char = 'y'; // 字符常量使用''

  // long 4 to 8 bytes; long long 至少 8 bytes
  long x_long = 0;
  long long x_long_long = 0;

  // 32位单精度浮点数
  float x_float = 0.0f; // 'f' 后缀

  // 64位双精度浮点数
  double x_double = 0.0; //没有后缀

  // 无符号整形 大于等于0
  unsigned short ux_short;
  unsigned int ux_int;
  unsigned long long ux_long_long;

  // 单引号中的字符可以和字符集中的整形互相转换
  '0'; // => 48 in the ASCII character set.
  'A'; // => 65 in the ASCII character set.

  // sizeof(T) 返回类型的占用空间
  // sizeof(obj) 返回变量或者表达式或者常量的占用空间.
  printf("%zu\n", sizeof(int)); // => 4 (on most machines with 4-byte words)

  // 数组以具体的大小声明
  char my_char_array[20]; // 占 1 * 20 = 20 bytes
  int my_int_array[20];   // 占 4 * 20 = 80 bytes

  // 使用初始化器初始化
  char my_array[20] = {0};
  char my_array[] = {0};

  // 运行时计算数组大小
  size_t my_array_size = sizeof(my_array) / sizeof(my_array[0]);

  // 取值
  my_array[0]; // => 0

  // 赋值
  my_array[1] = 2;
  printf("%d\n", my_array[1]); // => 2

  // 变长数组
  printf("Enter the array size: ");
  int array_size;
  scanf(stdin, "%d", &array_size);
  int var_length_array[array_size]; // declare the VLA
  printf("sizeof array = %zu\n", sizeof var_length_array);

  // 字符串是字符的数组，以NULL/0x00/\0字符结束
  // 双引号""
  char a_string[20] = "This is a string"; //{'T','h','i','s'....}
  printf("%s\n", a_string);               // %s formats a string

  printf("%d\n", a_string[16]); // => 0
  // i.e., byte #17 is 0 (as are 18, 19, and 20)

  // 单引号''包围的单个字符，实际是int类型，而非char类型
  int cha = 'a';  // fine
  char chb = 'a'; // fine too (implicit conversion from int to char)

  // 多维数组
  int multi_array[2][5] = {
      {1, 2, 3, 4, 5},
      {6, 7, 8, 9, 0}};
  // 获取元素
  int array_int = multi_array[0][2]; // => 3

  ///////////////////////////////////////
  // 操作符
  ///////////////////////////////////////

  // 多变量声明
  int i1 = 1, i2 = 2;
  float f1 = 1.0, f2 = 2.0;

  int b, c;
  b = c = 0;

  // 算术运算符
  i1 + i2; // => 3
  i2 - i1; // => 1
  i2 *i1;  // => 2
  i1 / i2; // => 0 (0.5, but truncated towards 0)

  // 为了得到浮点值，操作数至少有一个是浮点值
  (float)i1 / i2;  // => 0.5f
  i1 / (double)i2; // => 0.5 // 同 double
  f1 / f2;         // => 0.5,

  // 取模
  11 % 3; // => 2 // mod

  //关系运算符
  // C语言没有布尔值
  // 0 代表 false, 其他代表 true.
  // 关系操作符返回0或者1
  3 == 2; // => 0 (false)
  3 != 2; // => 1 (true)
  3 > 2;  // => 1
  3 < 2;  // => 0
  2 <= 2; // => 1
  2 >= 2; // => 1

  // 不存在链式关系运算 python
  // 下面的表达式不会有编译错误，他被理解成 `(0 < a) < 2`.
  // 这个表达式恒为1（ture），
  // 因为(0 < a) 可能是0或者1 ，且0或者1恒小于2
  int between_0_and_2 = 0 < a < 2;
  // 正确写法
  int between_0_and_2 = 0 < a && a < 2;

  // 逻辑运算符可作用于int
  !3;     // => 0 (Logical not)
  !0;     // => 1
  1 && 1; // => 1 (Logical and)
  0 && 1; // => 0
  0 || 1; // => 1 (Logical or)
  0 || 0; // => 0

  // 三元条件表达式 ( ? : )
  int e = 5;
  int f = 10;
  int z;
  z = (e > f) ? e : f; // => 10 "if e > f return e, else return f."

  // 累加、累减操作符
  int j = 0;
  int s += j++; // 先返回 j 然后自增 j. (s = 0, j = 1)
  // int s += j; j = j+1;
  s += ++j; // 先自增 j,然后返回 j. (s = 2, j = 2)
  // j = j +1; s += j;
  // j-- and --j 同理

  // 位运算符
  ~0x0000000F; // => 0xFFFFFFF0 按位取反
  0x0F & 0xF0; // => 0x00 按位与
  0x0F | 0xF0; // => 0xFF 按位或
  0x04 ^ 0x0F; // => 0x0B 按位异或 同为0，异为1
  0x01 << 1;   // => 0x02 左移1位
  0x02 >> 1;   // => 0x01 右移1位

  ///////////////////////////////////////
  // 控制结构
  ///////////////////////////////////////

  if (0)
  {
    printf("I am never run\n");
  }
  else if (0)
  {
    printf("I am also never run\n");
  }
  else
  {
    printf("I print\n");
  }

  // While循环
  int ii = 0;
  while (ii < 10)
  {
    printf("%d, ", ii++); // ii++ increments ii AFTER using its current value.
  }                       // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

  while (1)
  {
    if (ii >= 10)
    {
      break;
    }
  }

  printf("\n");

  int kk = 0;
  do
  {
    printf("%d, ", kk);
  } while (++kk < 10); // ++kk increments kk BEFORE using its current value.
  // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

  printf("\n");

  // For循环
  int jj;
  for (; jj < 10; jj++)
  {
    printf("%d, ", jj);
  } // => prints "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, "

  printf("\n");

  // 空循环体用 ; 代替
  int i;
  for (i = 0; i <= 5; i++)
  {
    ;
  }
  // Or
  for (i = 0; i <= 5; i++)
    ;

  for (i = 0; i < 5; i++)
  {
    for (int j = 0; j < 6; j++)
    {
      if (i == 2 && j == 3)
      {
        ;
      }
      else
      {
        ;
      }
    }
  }
  // swtich分支结构
  switch (a)
  {
  case 0: // 需要常量表达式，如emun else if
    printf("Hey, 'a' equals 0!\n");
    break; // 如果不加break,语句将继续执行
  case 1:
    printf("Huh, 'a' equals 1!\n");
    break;
    // 语句将继续执行，直到遇到下一个break
  case 3:
      printf("Look at that.. 'a' is either 3, or 4\n");
  case 4:
    printf("Look at that.. 'a' is either 3, or 4\n");
    break;
  default:
    // 没有匹配项，进入default分支
    fputs("Error!\n", stderr);
    exit(-1);
    break;
  }

  ///////////////////////////////////////
  // 类型转换
  ///////////////////////////////////////

  // C语言中，每个值都有类型
  // 并且提供了类型转换的操作

  int x_hex = 0x01; // 16进制整形变量

  // Casting between types will attempt to preserve their numeric values
  printf("%d\n", x_hex);        // => Prints 1
  printf("%d\n", (short)x_hex); // => Prints 1
  printf("%d\n", (char)x_hex);  // => Prints 1

  // Types will overflow without warning
  printf("%d\n", (unsigned char)257); // => 1 (Max char = 255 if char is 8 bits long)

  // For determining the max value of a `char`, a `signed char` and an `unsigned char`,
  // respectively, use the CHAR_MAX, SCHAR_MAX and UCHAR_MAX macros from <limits.h>

  // Integral types can be cast to floating-point types, and vice-versa.
  printf("%f\n", (double)100); // %f always formats a double...
  printf("%f\n", (float)100);  // ...even with a float.
  printf("%d\n", (char)100.0);

  //Special characters:
  /*
'\a'; // alert (bell) character
'\n'; // newline character
'\t'; // tab character (left justifies text)
'\v'; // vertical tab
'\f'; // new page (form feed)
'\r'; // carriage return
'\b'; // backspace character
'\0'; // NULL character. Usually put at end of strings in C.
//   hello\n\0. \0 used by convention to mark end of string.
'\\'; // backslash
'\?'; // question mark
'\''; // single quote
'\"'; // double quote
'\xhh'; // hexadecimal number. Example: '\xb' = vertical tab character
'\0oo'; // octal number. Example: '\013' = vertical tab character

//print formatting:
"%d";    // integer
"%3d";   // integer with minimum of length 3 digits (right justifies text)
"%s";    // string
"%f";    // float
"%ld";   // long
"%3.2f"; // minimum 3 digits left and 2 digits right decimal float
"%c";    // char
"%x";    // hexadecimal 0xFF,0x11
"%o";    // octal
"%%";    // prints %
*/

  ///////////////////////////////////////
  // Order of Evaluation
  ///////////////////////////////////////

  //---------------------------------------------------//
  //        Operators                  | Associativity //
  //---------------------------------------------------//
  // () [] -> .                        | left to right //
  // ! ~ ++ -- + = *(type)sizeof       | right to left //
  // * / %                             | left to right //
  // + -                               | left to right //
  // << >>                             | left to right //
  // < <= > >=                         | left to right //
  // == !=                             | left to right //
  // &                                 | left to right //
  // ^                                 | left to right //
  // |                                 | left to right //
  // &&                                | left to right //
  // ||                                | left to right //
  // ?:                                | right to left //
  // = += -= *= /= %= &= ^= |= <<= >>= | right to left //
  // ,                                 | left to right //
  //---------------------------------------------------//
