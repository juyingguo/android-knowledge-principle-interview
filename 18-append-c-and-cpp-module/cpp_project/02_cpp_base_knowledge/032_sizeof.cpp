#include <iostream>
using namespace std;

/**
sizeof 是一个关键字，它是一个编译时运算符，用于判断变量或数据类型的字节大小。

sizeof 运算符可用于获取类、结构、共用体和其他用户自定义数据类型的大小。
*/

int main()
{
   cout << "Size of char : " << sizeof(char) << endl;
   cout << "Size of int : " << sizeof(int) << endl;
   cout << "Size of short int : " << sizeof(short int) << endl;
   cout << "Size of long int : " << sizeof(long int) << endl;
   cout << "Size of float : " << sizeof(float) << endl;
   cout << "Size of double : " << sizeof(double) << endl;
   cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;
   return 0;
}
