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
	 int i1=10,i2=20,i3=30,i;
	 double d1=30.87,d2=90.2345789,d3=-20.76,d;
	 long g1=67845,g2=-912456,g3=673456,g;
	 i=max(i1,i2,i3);
	 d=max(d1,d2,d3);
	 g=max(g1,g2,g3);
	 cout<<"i_max="<<i<<endl;
	 cout<<"d_max="<<d<<endl;
	 cout<<"g_max="<<g<<endl;
 	return 0;
}

