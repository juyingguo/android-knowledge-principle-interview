#include <iostream>
using namespace std;

int main ()
{
   // 带有 5 个元素的双精度浮点型数组
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double /*const*/ *p;

   p = balance;

   *p = 10;

   // 输出数组中每个元素的值
   cout << "使用指针的数组值 " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(p + " << i << ") : ";
       cout << *(p + i) << endl;
   }

   cout << "使用 balance 作为地址的数组值 " << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "*(balance + " << i << ") : ";
       cout << *(balance + i) << endl;
   }
   cout << "使用下标访问数组值 " << endl;
 	for ( int i = 0; i < 5; i++ )
   {
       cout << "balance[" << i << "] : ";
       cout << balance[i] << endl;
   }
   return 0;
}
