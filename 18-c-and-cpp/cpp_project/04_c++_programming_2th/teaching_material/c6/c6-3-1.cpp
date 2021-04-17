#include  <iostream>
using namespace std;
int main()
{
    void swap(int *p1,int *p2);
    int *pointer_1,*pointer_2,a,b;
    cin>>a>>b;
    pointer_1=&a;
    pointer_2=&b;
    cout<<"addr pointer_1 = "<<pointer_1<<",addr pointer_2 = "<<pointer_2<<endl;
    if(a<b) swap(pointer_1,pointer_2);
    cout<<"after swap,addr pointer_1 = "<<pointer_1<<",addr pointer_2 = "<<pointer_2<<endl;
    cout<<"max="<<a<<" min="<<b<<endl;
    return 0;
}
/* 改变指针所指向的变量的值。也没有改变形式参数的指针变量的值。实参指针变量并没有改变。 */
void swap(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
    cout<<"swap call,addr p1 = "<<p1<<",addr p2 = "<<p2<<endl;
}
