#include <iostream>
using namespace std;
int main()
 { void input(int *number); 
   void max_min_value(int *number);  
   void output(int *number);
   int number[10];
   input(number);                           // ��������10�����ĺ��� 
   max_min_value(number);                   // ���ý������� 
   output(number);                          // ����������� 
   return 0;
}

 void input(int *number)                 // ����10�����ĺ��� 
 {int i;
  cout<<"input 10 numbers:";
  for (i=0;i<10;i++)
    cin>>number[i];
  }

 void max_min_value(int *number)            // �������� 
 { int *max,*min,*p,temp;
   max=min=number;
   for (p=number+1;p<number+10;p++)
     if (*p>*max) max=p;                 // ��������ַ���� max  
     else if (*p<*min) min=p;            // ��С����ַ���� min  
     temp=number[0];number[0]=*min;*min=temp;  // ����С�����һ������ 
     temp=number[9];number[9]=*max;*max=temp;  // ����С�����һ������ 
  }

void output(int *number)                  // ������� 
  {int *p;
   cout<<"now,they are:    ";
   for (p=number;p<number+10;p++)
     cout<<*p<<" ";
   cout<<endl;
   return;
   }
 

	
   


 
