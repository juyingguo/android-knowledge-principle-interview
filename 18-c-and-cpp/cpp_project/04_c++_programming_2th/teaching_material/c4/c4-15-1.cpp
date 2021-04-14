//file1.cpp
#include <iostream>
using namespace std;
int main()
{
    /*extern*/ int max(int,int);//c++允许声明函数时省略extern;
    int a,b;
    cin>>a>>b;
    cout<<max(a,b)<<endl;
    return 0;
}
