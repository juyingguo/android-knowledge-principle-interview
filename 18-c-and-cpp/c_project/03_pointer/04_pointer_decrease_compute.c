#include <stdio.h>
 
const int MAX = 3;
 
int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;
 
   /* ָ���е��������һ��Ԫ�صĵ�ַ */
   ptr = &var[MAX - 1];
   for (i = MAX; i >0; i--)
   {
 
      printf("�洢��ַ��var[%d] = %x\n", i-1, ptr );
      printf("�洢ֵ��var[%d] = %d\n", i-1, *ptr );
 
      /* �ƶ�����һ��λ�� */
      ptr--;
   }
   return 0;
}
