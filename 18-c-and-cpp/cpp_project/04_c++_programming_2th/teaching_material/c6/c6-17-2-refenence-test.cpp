#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a=10;
    int &b=a;
    int &c = b;
    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;//��ͼ�������õ�Ӧ�ã����󣨡�c++������Ƶ�2�� ̷��ǿ��������ʵ�������gcc�ǿ�����������ģ�����������

    c = 50;

    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;

    int &d = a;//��ͼʹa�ֱ�Ϊd�����á����󣨡�c++������Ƶ�2�� ̷��ǿ��������ʵ�������gcc�ǿ�����������ģ�����������
    d = 800;
    cout <<d<<endl;
    cout <<a<<setw(5)<<b<<setw(5)<<c<<endl;

    return 0;
}
