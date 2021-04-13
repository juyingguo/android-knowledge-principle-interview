#include <iostream>
#include <string>
using namespace std;
int main()
{ string stars="*****";
  int i,j;
  for (i=0;i<5;i++)              // 输出5行 
   { cout<<"    ";               // 每行前面留4个空格
     for (j=1;j<=i;j++)
       cout<<" ";               // 每行再插入i个空格    
     cout<<stars<<endl;         // 输出5个*号
  }   
  return 0;
} 
