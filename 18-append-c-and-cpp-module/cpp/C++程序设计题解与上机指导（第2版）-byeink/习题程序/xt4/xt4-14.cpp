#include <iostream>
using namespace std;
//#define LETTER 1                 
int main()
{char c;
 cin>>c;
 #if LETTER                     
     if(c>='a' && c<='z')
       c=c-32;
 #else                          
     if(c>='A' && c<='Z')        
       c=c+32;
 #endif
 cout<<c<<endl;
 return 0;
}


