#include <stdio.h>
#include <string.h>

//union 最后赋给变量的值占用了内存位置
union Data
{
   int i;
   float f;
   char  str[20];
};

int main( )
{
   union Data data;

   data.i = 10;

   strcpy( data.str, "C Programming");
   data.f = 220.5;//因为最后赋给变量的值占用了内存位置

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

   return 0;
}
