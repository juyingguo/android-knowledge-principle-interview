#include <iostream>
using namespace std;
int main()
  {int day,x1,x2;
   day=9;
   x2=1;
   while(day>0)
    {x1=(x2+1)*2;        // ��1����������ǵ�2����������1���2�� 
     x2=x1;
     day--;
    }
   cout<<"total="<<x1<<endl;
   return 0;
   } 
  
