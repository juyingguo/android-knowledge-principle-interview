#include <iostream>
#include <iomanip>
using namespace std;
int main ( )
{float h,r,l,s,sq,vq,vz;
 const float pi=3.1415926;
 cout<<"please enter r,h:";
 cin>>r>>h;
 l=2*pi*r;
 s=r*r*pi;
 sq=4*pi*r*r;
 vq=3.0/4.0*pi*r*r*r;
 vz=pi*r*r*h;
 cout<<setiosflags(ios::fixed)<<setiosflags(ios::right)
	 <<setprecision(2);
 cout<<"l= "<<setw(10)<<l<<endl;
 cout<<"s= "<<setw(10)<<s<<endl;
 cout<<"sq="<<setw(10)<<sq<<endl;
 cout<<"vq="<<setw(10)<<vq<<endl;
 cout<<"vz="<<setw(10)<<vz<<endl;
 return 0;
}  

