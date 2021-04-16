#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a=10;
    int &b=a;
    int &c = b;
    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;//试图建立引用的应用，错误（《c++程序设计第2版 谭浩强》）。（实际情况，gcc是可以正常编译的，运行正常）

    c = 50;

    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;

    int &d = a;//试图使a又变为d的引用。错误（《c++程序设计第2版 谭浩强》）。（实际情况，gcc是可以正常编译的，运行正常）
    d = 800;
    cout <<d<<endl;
    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;

    return 0;
}
