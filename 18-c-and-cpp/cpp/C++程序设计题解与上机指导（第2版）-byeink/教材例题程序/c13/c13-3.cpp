#include <iostream>
using namespace std;
int main()
{int a=21;
 cout.setf(ios::showbase);
 cout<<"dec:"<<a<<endl;
 cout.unsetf(ios::dec);
 cout.setf(ios::hex);
 cout<<"hex:"<<a<<endl;
 cout.unsetf(ios::hex);
 cout.setf(ios::oct);
 cout<<"oct:"<<a<<endl;
 char *pt="China";
 cout.width(10);
 cout<<pt<<endl;
 cout.width(10);
 cout.fill('*');
 cout<<pt<<endl;
 double pi=22.0/7.0;
 cout.setf(ios::scientific);
 cout<<"pi=";
 cout.width(14);
 cout<<pi<<endl;
 cout.unsetf(ios::scientific);
 cout.setf(ios::fixed);
 cout.width(12);
 cout.setf(ios::showpos);
 cout.setf(ios::internal);
 cout.precision(6);
 cout<<pi<<endl;
 return 0;
}
