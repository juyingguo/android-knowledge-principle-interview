#include <stdio.h>
#include <string.h>

//union ��󸳸�������ֵռ�����ڴ�λ��
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
   data.f = 220.5;//��Ϊ��󸳸�������ֵռ�����ڴ�λ��

   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);

   return 0;
}
