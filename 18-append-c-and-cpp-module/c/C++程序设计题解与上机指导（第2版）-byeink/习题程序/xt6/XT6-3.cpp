#include <iostream>
using namespace std;
int main()
 { void input(int *number); 
   void max_min_value(int *number);  
   void output(int *number);
   int number[10];
   input(number);                           // 调用输入10个数的函数 
   max_min_value(number);                   // 调用交换函数 
   output(number);                          // 调用输出函数 
   return 0;
}

 void input(int *number)                 // 输入10个数的函数 
 {int i;
  cout<<"input 10 numbers:";
  for (i=0;i<10;i++)
    cin>>number[i];
  }

 void max_min_value(int *number)            // 交换函数 
 { int *max,*min,*p,temp;
   max=min=number;
   for (p=number+1;p<number+10;p++)
     if (*p>*max) max=p;                 // 将大数地址赋给 max  
     else if (*p<*min) min=p;            // 将小数地址赋给 min  
     temp=number[0];number[0]=*min;*min=temp;  // 将最小数与第一数交换 
     temp=number[9];number[9]=*max;*max=temp;  // 将最小数与第一数交换 
  }

void output(int *number)                  // 输出函数 
  {int *p;
   cout<<"now,they are:    ";
   for (p=number;p<number+10;p++)
     cout<<*p<<" ";
   cout<<endl;
   return;
   }
 

	
   


 
