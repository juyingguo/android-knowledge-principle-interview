#include <iostream>
using namespace std;

void f(int &a)

 {
 cout << "f(" << a  << ") is being called" << endl;
}

void g(const int &a)

{
 cout << "g(" << a << ") is being called" << endl;
}

 int main()

 {
 int a = 3, b = 4;
 f(a);
 f(a + b);  //编译错误，把临时变量作为非const的引用参数传递了
 g(a + b);  //OK，把临时变量作为const&传递是允许的
}
