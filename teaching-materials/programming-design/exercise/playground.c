#include <stdio.h>
int main()
{
   int a, b;
   char cc;
   char string[20];
   scanf("%d %c %s", &a, &cc, &string);
   ;
   // printf("Hello, World!");

   // char x_char = 0;
   // char y_char = 'y';

   // printf("%d", x_char);
   // printf("%c", y_char);

   char my_array1[20] = {1};
   char my_array2[] = {1};

   printf("%d\n", sizeof(my_array1));
   printf("%d\n", sizeof(my_array2));

   printf("%7.4f\n", 12345678.87654321);

   return 0;
}