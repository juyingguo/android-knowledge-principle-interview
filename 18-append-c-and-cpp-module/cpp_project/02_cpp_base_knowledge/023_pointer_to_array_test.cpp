#include <iostream>
using namespace std;

int main ()
{
   // ���� 5 ��Ԫ�ص�˫���ȸ���������
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double /*const*/ *p;

   p = balance;

   *p = 10;

   // ���������ÿ��Ԫ�ص�ֵ
   cout << "ʹ��ָ�������ֵ " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

   cout << "ʹ�� balance ��Ϊ��ַ������ֵ " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(balance + " << i << ") : ";
       cout << *(balance + i) << endl;
   }
   cout << "ʹ���±��������ֵ " << endl;
 	for ( int i = 0; i < 5; i++ )
   {
       cout << "balance[" << i << "] : ";
       cout << balance[i] << endl;
   }
   return 0;
}
