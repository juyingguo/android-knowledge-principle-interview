#include <iostream>
using namespace std;
 
// 函数声明,不用参数名 
int max(int , int );
 
int main ()
{
   // 局部变量声明
   int a = 20;
   int b = 30;
   int ret;
 
   // 调用函数来获取最大值
   ret = max(a, b);
 
   cout << "Max value is : " << ret << endl;
 
   return 0;
}
 
// 函数返回两个数中较大的那个数
int max(int num1, int num2) 
{
   // 局部变量声明
   int result;
 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
 
   return result; 
} 
