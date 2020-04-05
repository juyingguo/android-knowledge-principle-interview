#include <iostream>
using namespace std;
int main()
{int max(int x,int y);              //函数声明
 int a,b,m;
 cin>>a>>b;
 m=max(a,b);                        //调用函数max，求出最大值，赋予m
 cout<<"max="<<m<<endl;
 return 0;
}

int max(int x,int y)
{int z;
 if(x>y) z=x;
 else z=y;
 return(z);
}
