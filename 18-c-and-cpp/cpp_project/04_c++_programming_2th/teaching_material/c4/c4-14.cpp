#include <iostream>
using namespace std;
int max(int,int);
int main()
{
    //ͬһ���ļ��е�ȫ�ֱ������ڶ���ǰʹ��ʱ����Ҫ��ʹ��extern��������������ͬ����ΪҲ���ܲ�ͬ������code:blocks ʹ�õ�gcc��û��externҲ���ᱨ�������н��������Ҫ�ģ��������ֵ��
    extern int a,b;
    cout<< "max(a,b)=" << max(a,b)<<endl;
    return 0;
}

int a=20,b=-8;
int max(int x,int y)
{
    int z;

    z=x>y?x:y;
    return z;
}
