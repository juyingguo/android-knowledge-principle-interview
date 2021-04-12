#include <iostream>
using namespace std;
int main ( )
  {int a,b,c,temp,max ;
   cout<<"please enter three integer numbers:";
   cin>>a>>b>>c;
   temp=(a>b)?a:b;                 /*  将a和b中的大者存入temp中 */
   max=(temp>c)?temp:c;            /*  将a和b中的大者与c比较，最大者存入max */
   cout<<"max="<<max<<endl;
   return 0;
  }

