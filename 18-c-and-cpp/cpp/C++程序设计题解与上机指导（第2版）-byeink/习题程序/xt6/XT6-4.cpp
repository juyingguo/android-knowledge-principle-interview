#include <iostream>
using namespace std;
int main()
 {void move(int *array,int n,int m);
  int number[20],n,m,i; 
  cout<<"how many numbers?";               // 询问共有多少个数 
  cin>>n;
  cout<<"input "<<n<<" numbers:"<<endl;    // 要求输入n个数 
  for (i=0;i<n;i++)
    cin>>number[i];
  cout<<"how many places do you want move?";  // 询问后移多少个位置
  cin>>m;
  move(number,n,m);                       //调用move 函数 
  cout<<"Now,they are:"<<endl;
  for (i=0;i<n;i++)
    cout<<number[i]<<" ";
  cout<<endl;
  return 0;
}

void move(int *array,int n,int m)             //使循环后移一次的函数
 {int *p,array_end;
  array_end=*(array+n-1);
  for (p=array+n-1;p>array;p--)
    *p=*(p-1);
  *array=array_end;
  m--;
  if (m>0) move(array,n,m); //递归调用,当循环次数m减至为0时,停止调用 
 }

	
 

	
   


 
