#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int *pointer_1,*pointer_2;
    a=100;b=10;
    pointer_1=&a;      //把变量ａ的地址赋给pointer_1
    pointer_2=&b;      //把变量ｂ的地址赋给pointer_2

    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(pointer_1) = " << sizeof(pointer_1) << endl;

    cout<<a<<" "<<b<<endl;
    cout<<*pointer_1<<" "<<*pointer_2<<endl;

    double d1 = 10.21f;
    double *pointer_d = &d1;//定义的时候赋值。同定义后再赋值pointer_d = &d1，此时不需要加*。


    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(d1) = " << sizeof(d1) << endl;
    cout << "sizeof(pointer_d) = " << sizeof(pointer_d) << endl;
    cout << "d1 = " << d1 << endl;

    cout << "*pointer_d = " << *pointer_d << endl;
    return 0;
}
