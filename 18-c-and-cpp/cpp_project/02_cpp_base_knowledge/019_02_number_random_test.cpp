#include <iostream>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
int main ()
{
   int i,j;
 
   // ��������
   srand( (unsigned)time( NULL ) );
 
   /* ���� 10 ������� */
   for( i = 0; i < 3; i++ )
   {
      // ����ʵ�ʵ������
      j= rand();
      cout <<"������� " << j << endl;
   }
 
   return 0;
}
