#include <iostream>
using namespace std;
int main()
{ char a[5]={'*','*','*','*','*'};
  int i,j,k;
  char space=' ';
  for (i=0;i<5;i++)              // 输出5行 
   { cout<<endl;                 // 输出每行前先换行 
     cout<<"    ";               // 每行前面留4个空格 
     for (j=1;j<=i;j++)
       cout<<space;              // 每行再留一个空格 
     for (k=0;k<5;k++)
       cout<<a[k];               // 每行输出5个*号
	}   
  cout<<endl;
   return 0;
} 
