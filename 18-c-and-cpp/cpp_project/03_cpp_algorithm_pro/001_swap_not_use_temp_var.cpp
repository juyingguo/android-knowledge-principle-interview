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
   // 局部变量声明
   int a = 50;
   int b = 200;
 
   cout << "交换前，a 的值：" << a << endl;
   cout << "交换前，b 的值：" << b << endl;
 
   // 调用函数来交换值
   swap(a, b);
 
   cout << "交换后，a 的值：" << a << endl;
   cout << "交换后，b 的值：" << b << endl;
 
   return 0;
}
