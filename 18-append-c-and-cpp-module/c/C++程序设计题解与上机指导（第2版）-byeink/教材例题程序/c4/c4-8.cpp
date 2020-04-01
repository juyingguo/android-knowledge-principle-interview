#include <iostream>
using namespace std;
int main()
{int max(int a,int b,int c=0);
 int a,b,c;
 cin>>a>>b>>c;
 cout<<"max(a,b,c)="<<max(a,b,c)<<endl;
 cout<<"max(a,b)="<<max(a,b)<<endl;
 return 0;
}

int max(int a,int b,int c)
{if(b>a) a=b;
 if(c>a) a=c;
 return a;
}

