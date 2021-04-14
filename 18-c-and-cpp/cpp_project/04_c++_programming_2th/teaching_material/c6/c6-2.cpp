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
    通过指针变量交换，达到获取大值
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
    直接通过变量交换，达到获取大值,同时变量值也互换了
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
    通过指针交换，达到获取大值,同时变量值也互换了
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
