#include <iostream>
using namespace std;
 
// ��������,���ò����� 
int max(int , int );
 
int main ()
{
   // �ֲ���������
   int a = 20;
   int b = 30;
   int ret;
 
   // ���ú�������ȡ���ֵ
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// ���������������нϴ���Ǹ���
int max(int num1, int num2) 
{
   // �ֲ���������
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
} 
