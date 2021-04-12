#include <iostream>
using namespace std;
int main ( )
  {int a,b,c;
   cout<<"please enter three integer numbers:";
   cin>>a>>b>>c;
   if(a<b)
     if(b<c)
       cout<<"max="<<c;
     else
       cout<<"max="<<b;
    else if (a<c)
        cout<<"max="<<c;
    else
        cout<<"max="<<a;
    cout<<endl;
	return 0;
  }

