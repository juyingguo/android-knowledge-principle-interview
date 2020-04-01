#include <iostream>
using namespace std;
int main ( )
  {int x,y;
   cout<<"enter x:";
   cin>>x;
   if (x<1)                            
      {y=x;
       cout<<"x="<<x<<", y=x="<<y;
      }
   else if (x<10)                     // 1¡Üx£¼10 
       {y=2*x-1;
        cout<<"x="<<x<<", y=2*x-1="<<y;
       }
        else                           // x¡Ý10 
         {y=3*x-11;
          cout<<"x="<<x<<", y=3*x-11="<<y;
         }
    cout<<endl;
	return 0;
}

