#include <iostream>

using namespace std;
class MyClass
{
public:
    int i{0};
    char cp{0};
//    char* cs{nullptr};
public:
    MyClass(int i):i(i){};
    MyClsss(char c)=delete;  //删除char版本的构造函数
//    MyClsss(char* cp2,int ip2){
//        cs = cp2;
//        i = ip2;
//    }/*=delete*/;  //删除char版本的构造函数
//    MyClsss(char c):cp(c){};  //删除char版本的构造函数
};
void Func(MyClass mc){};
//void Func(MyClass mc)=delete;
int main()
{
  Func(3);
  Func('a');  //编译不能通过
  MyClass m1(3);
  MyClass m2('a');  //编译不能通过.  实测发现：不同cpp版本表现可能不同。
//  MyClass m3("test",1);  //编译不能通过.
//  MyClass *m3 = new MyClass("test",1);
  cout<< "m1.i: "<< m1.i<<endl;
  cout<< "m2.i: "<< m2.i<<endl;
//  cout<< "m3.i:"<< m3->i<<" m3.cs:"<<m3->cs<<endl;
}
