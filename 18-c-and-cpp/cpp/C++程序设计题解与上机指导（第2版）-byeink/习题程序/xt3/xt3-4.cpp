#include <iostream>
using namespace std;
int main ( )
{char c1,c2;
 cout<<"请输入两个字符c1,c2:";
 c1=getchar();        //将输入的第一个字符赋给c1
 c2=getchar();        //将输入的第二个字符赋给c2 
 cout<<"用putchar函数输出结果为:";
 putchar(c1);
 putchar(c2);
 cout<<endl;
 cout<<"用cout语句输出结果为:";
 cout<<c1<<c2<<endl;
 return 0;
}
