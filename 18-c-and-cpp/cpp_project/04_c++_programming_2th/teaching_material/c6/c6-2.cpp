#include  <iostream>
using namespace std;
void max();
void max2();
void max3();

int main()
{
    max();
    max2();
    max3();
    return 0;
}
/**
    ͨ��ָ������������ﵽ��ȡ��ֵ
 */
void max()
{
    int *p1,*p2,*p,a,b;
    cin>>a>>b;
    p1=&a;
    p2=&b;
    if(a<b)
    {p=p1;p1=p2;p2=p;}
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"max="<<*p1<<" min="<<*p2<<endl;
}
/**
    ֱ��ͨ�������������ﵽ��ȡ��ֵ,ͬʱ����ֵҲ������
 */
void max2()
{
    int *p1,*p2,a,b,c;
    cin>>a>>b;
    p1=&a;
    p2=&b;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"max="<<*p1<<" min="<<*p2<<endl;
}
/**
    ͨ��ָ�뽻�����ﵽ��ȡ��ֵ,ͬʱ����ֵҲ������
 */
void max3()
{
    int *p1,*p2,a,b,c;
    cin>>a>>b;
    p1=&a;
    p2=&b;
    if(a<b)
    {
        int temp = a;
        *p1 = *p2;
        *p2 = temp;
    }
    cout<<"a="<<a<<" b="<<b<<endl;
    cout<<"max="<<*p1<<" min="<<*p2<<endl;
}
