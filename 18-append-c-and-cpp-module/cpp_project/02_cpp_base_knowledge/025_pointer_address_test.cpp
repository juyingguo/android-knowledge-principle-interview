#include <iostream>
 
using namespace std;
 
int main ()
{
   int  var = 20;   // ʵ�ʱ���������
   int  *ip;        // ָ�����������
 
   ip = &var;       // ��ָ������д洢 var �ĵ�ַ
 
   cout << "Value of var variable: ";
   cout << var << endl;
 
   // �����ָ������д洢�ĵ�ַ
   cout << "Address stored in ip variable: ";
   cout << ip << endl;
 
   // ����ָ���е�ַ��ֵ
   cout << "Value of *ip variable: ";
   cout << *ip << endl;
 
   return 0;
}
