//file1.cpp
#include <iostream>
using namespace std;
int main()
{
    /*extern*/ int max(int,int);//c++������������ʱʡ��extern;
    int a,b;
    cin>>a>>b;
    cout<<max(a,b)<<endl;
    return 0;
}
