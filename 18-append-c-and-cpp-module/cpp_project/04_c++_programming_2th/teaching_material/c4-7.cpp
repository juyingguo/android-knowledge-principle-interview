#include <iostream>
using namespace std;
template <typename T>
T max(T a,T b,T c)
{
	if(b>a) a=b;
 	if(c>a) a=c;
 	
	return a;
}

int main()
{
	 int i1=185,i2=-76,i3=567,i;
	 double d1=56.87,d2=90.23,d3=-3214.76,d;
	 long g1=67845,g2=-912456,g3=673456,g;
	 i=max(i1,i2,i3);
	 d=max(d1,d2,d3);
	 g=max(g1,g2,g3);
	 cout<<"i_max="<<i<<endl;
	 cout<<"d_max="<<d<<endl;
	 cout<<"g_max="<<g<<endl;
 	return 0;
}

