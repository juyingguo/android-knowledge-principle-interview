#include <iostream>
using namespace std;

void swap(int a, int b)
{
    a=a+b;
    b=a-b;
    a=a-b;
    return;
}

int main ()
{
   // �ֲ���������
   int a = 50;
   int b = 200;
 
   cout << "����ǰ��a ��ֵ��" << a << endl;
   cout << "����ǰ��b ��ֵ��" << b << endl;
 
   // ���ú���������ֵ
   swap(a, b);
 
   cout << "������a ��ֵ��" << a << endl;
   cout << "������b ��ֵ��" << b << endl;
 
   return 0;
}
