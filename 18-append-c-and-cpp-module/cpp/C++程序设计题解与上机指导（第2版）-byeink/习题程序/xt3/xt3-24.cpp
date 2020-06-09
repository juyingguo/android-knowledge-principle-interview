#include <iostream>
using namespace std;
int main()
  {int i,k;
    for (i=0;i<=3;i++)         // 输出上面4行*号 
      {for (k=0;k<=2*i;k++)
        cout<<"*";           // 输出*号 
       cout<<endl;           //输出完一行*号后换行 
      }
    for (i=0;i<=2;i++)        // 输出下面3行*号 
      {for (k=0;k<=4-2*i;k++)
         cout<<"*";          // 输出*号 
       cout<<endl;           // 输出完一行*号后换行
      }
	return 0;
    } 

