#include <iostream>
using namespace std;
int main()
{char diamond[][5]={{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ','*'}};
 int i,j;
 for (i=0;i<5;i++)
   {for (j=0;j<5;j++)
     cout<<diamond[i][j];
    cout<<endl;
	}
  return 0;
 }
