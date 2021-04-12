#include <stdio.h>
#include <string.h>

union Data
{
   int i;
   float f;
   double d;
   char  str[2];
};

int main( )
{
   union Data data;

    printf( "Memory size occupied by long : %d\n", sizeof(long));
   printf( "Memory size occupied by int : %d\n", sizeof(int));
   printf( "Memory size occupied by float : %d\n", sizeof(float));
   printf( "Memory size occupied by double : %d\n", sizeof(double));
   printf( "Memory size occupied by char : %d\n", sizeof(char));
   printf( "Memory size occupied by data : %d\n", sizeof(data));//显示最大的一个。

   return 0;
}
