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
 f(a + b);  //������󣬰���ʱ������Ϊ��const�����ò���������
 g(a + b);  //OK������ʱ������Ϊconst&�����������
}
