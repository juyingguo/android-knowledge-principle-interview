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
    MyClsss(char c)=delete;  //ɾ��char�汾�Ĺ��캯��
//    MyClsss(char* cp2,int ip2){
//        cs = cp2;
//        i = ip2;
//    }/*=delete*/;  //ɾ��char�汾�Ĺ��캯��
//    MyClsss(char c):cp(c){};  //ɾ��char�汾�Ĺ��캯��
};
void Func(MyClass mc){};
//void Func(MyClass mc)=delete;
int main()
{
  Func(3);
  Func('a');  //���벻��ͨ��
  MyClass m1(3);
  MyClass m2('a');  //���벻��ͨ��.  ʵ�ⷢ�֣���ͬcpp�汾���ֿ��ܲ�ͬ��
//  MyClass m3("test",1);  //���벻��ͨ��.
//  MyClass *m3 = new MyClass("test",1);
  cout<< "m1.i: "<< m1.i<<endl;
  cout<< "m2.i: "<< m2.i<<endl;
//  cout<< "m3.i:"<< m3->i<<" m3.cs:"<<m3->cs<<endl;
}
