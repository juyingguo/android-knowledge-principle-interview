#include <iostream>
 
using namespace std;
 
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // ���ص� i ��Ԫ�ص�����
}
 
// Ҫ�������涨�庯����������
int main ()
{
 
   cout << "�ı�ǰ��ֵ" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 50; // �ı�� 2 ��Ԫ��
   setValues(3) = 25;  // �ı�� 4 ��Ԫ��
 
   cout << "�ı���ֵ" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
   return 0;
}
