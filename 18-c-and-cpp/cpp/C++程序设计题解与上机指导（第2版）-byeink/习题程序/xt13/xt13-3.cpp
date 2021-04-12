#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
 for(int n=1;n<8;n++)
 cout<<setw(20-n)<<setfill(' ')<<" "        //nm
     <<setw(2*n-1)<<setfill('B')<<"B"<<endl;
 return 0;
}

