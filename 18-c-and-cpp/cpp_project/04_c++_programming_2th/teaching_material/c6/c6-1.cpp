#include <iostream>
using namespace std;
int main()
{
    int a,b;
    int *pointer_1,*pointer_2;
    a=100;b=10;
    pointer_1=&a;      //�ѱ�����ĵ�ַ����pointer_1
    pointer_2=&b;      //�ѱ�����ĵ�ַ����pointer_2

    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(pointer_1) = " << sizeof(pointer_1) << endl;

    cout<<a<<" "<<b<<endl;
    cout<<*pointer_1<<" "<<*pointer_2<<endl;

    double d1 = 10.21f;
    double *pointer_d = &d1;//�����ʱ��ֵ��ͬ������ٸ�ֵpointer_d = &d1����ʱ����Ҫ��*��


    cout << "sizeof(double) = " << sizeof(double) << endl;
    cout << "sizeof(d1) = " << sizeof(d1) << endl;
    cout << "sizeof(pointer_d) = " << sizeof(pointer_d) << endl;
    cout << "d1 = " << d1 << endl;

    cout << "*pointer_d = " << *pointer_d << endl;
    return 0;
}
