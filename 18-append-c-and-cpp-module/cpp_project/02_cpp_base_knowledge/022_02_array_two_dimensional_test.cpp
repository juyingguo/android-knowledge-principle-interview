#include <iostream>
using namespace std;
 
int main ()
{
   // һ������ 5 �� 2 �е�����
   int a[5][2] = { {0,0}, {1,2}, {2,4}, {3,6},{4,8}};
 
   // ���������ÿ��Ԫ�ص�ֵ                      
   for ( int i = 0; i < 5; i++ )
      for ( int j = 0; j < 2; j++ )
      {
         cout << "a[" << i << "][" << j << "]: ";
         cout << a[i][j]<< endl;
      }
 
   return 0;
}
