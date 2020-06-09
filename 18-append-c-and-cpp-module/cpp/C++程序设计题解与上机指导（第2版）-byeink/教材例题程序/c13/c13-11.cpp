#include <fstream>
using namespace std;
int main()
{int a[10];
 ofstream outfile("f1.dat");
 if(!outfile)
  {cerr<<"open error!"<<endl;
   exit(1);
  }
 cout<<"enter 10 integer numbers:"<<endl;
 for(int i=0;i<10;i++)
  {cin>>a[i];
   outfile<<a[i]<<" ";}
 outfile.close();
 return 0;
}
   

