#include <stdio.h>
 
int main ()
{
   char *cps[2] = {"hello","test"};
   
   /* 输出数组中每个元素的值 */
   int j;
   for (j = 0; j < 2; j++ )
   {
      printf("cps[%d] = %s\n", j, cps[j] );
   }
   char *p  = "jim";
   
 	printf("*p = %s\n",p);
   return 0;
}
