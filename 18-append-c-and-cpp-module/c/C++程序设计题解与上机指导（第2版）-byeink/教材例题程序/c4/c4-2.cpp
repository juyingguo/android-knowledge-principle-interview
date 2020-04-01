#include <iostream>
using namespace std;
int max(int x,int y)
{int z;
 z=x>y?x:y;
 return(z);
}

int main()
{int a,b,c;
 cout<<"please enter two integer numbers:"; 
 cin>>a>>b;
 c=max(a,b);
 cout<<"max="<<c<<endl;
 return 0;
}

