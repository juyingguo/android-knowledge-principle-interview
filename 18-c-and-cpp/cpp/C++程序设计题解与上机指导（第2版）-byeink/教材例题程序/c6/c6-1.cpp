#include <iostream>
using namespace std;
int main()
{int a,b;
 int *pointer_1,*pointer_2;
 a=100;b=10;
 pointer_1=&a;      //�ѱ�����ĵ�ַ����pointer_1
 pointer_2=&b;      //�ѱ�����ĵ�ַ����pointer_2
 cout<<a<<" "<<b<<endl;
 cout<<*pointer_1<<" "<<*pointer_2<<endl;
 return 0;
}