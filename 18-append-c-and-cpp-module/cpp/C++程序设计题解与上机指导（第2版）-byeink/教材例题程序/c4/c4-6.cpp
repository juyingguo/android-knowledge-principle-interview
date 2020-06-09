#include <iostream>
using namespace std;
int main()
{int max(int a,int b,int c);
 int max(int a,int b);
 int a=8,b=-12,c=7;
 cout<<"max(a,b,c)="<<max(a,b,c)<<endl;
 cout<<"max(a,b)="<<max(a,b)<<endl;
 return 0;
}

int max(int a,int b,int c)
{if(b>a) a=b;
 if(c>a) a=c;
 return a;
}

int max(int a,int b)
{if(a>b) return a;
 else return b;
}



