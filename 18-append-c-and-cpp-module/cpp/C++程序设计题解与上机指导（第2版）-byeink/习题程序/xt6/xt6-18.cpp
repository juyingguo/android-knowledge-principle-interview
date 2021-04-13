#include <iostream>
using namespace std;
int main()
{char *month_name[13]={"illegal month","January","February","March","April",
   "May","June","July","August","September","October", "November","December"};
int n;
cout<<"input month:"<<endl;
cin>>n;
if ((n<=12) && (n>=1))
   cout<<"It is "<<*(month_name+n)<<endl;
else
  cout<<"It is wrong"<<endl;
return 0;
} 
