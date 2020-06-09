#include <iostream>
using namespace std;
int main()
{int a,b;
 int *pointer_1,*pointer_2;
 a=100;b=10;
 pointer_1=&a;      //把变量ａ的地址赋给pointer_1
 pointer_2=&b;      //把变量ｂ的地址赋给pointer_2
 cout<<a<<" "<<b<<endl;
 cout<<*pointer_1<<" "<<*pointer_2<<endl;
 return 0;
}