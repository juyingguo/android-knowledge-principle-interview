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
/* û�иı�ʵ��ָ�������ֵ�����ı�����ʽ������ָ�������ֵ��ָ����ָ��ı�����ֵ��û�иı䡣 */
void swap(int *p1,int *p2)
{
    int help = 0;
    int *temp = &help;
    temp=p1;
    p1=p2;
    p2=temp;

    cout<<"swap call,addr p1 = "<<p1<<",addr p2 = "<<p2<<endl;
}
