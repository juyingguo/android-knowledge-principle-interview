#include <iostream>
using namespace std;
int main()
{void hanoi(int n,char one,char two,char three);
 int m;
 cout<<"input the number of diskes:";
 cin>>m;
 cout<<"The steps of moving "<<m<<" disks:"<<endl;
 hanoi(m,'A','B','C');
 return 0;
}

void hanoi(int n,char one,char two,char three)
	 //½«n¸öÅÌ´Óone×ù½èÖútwo×ù£¬ÒÆµ½three×ù
 {void move(char x,char y);
  if(n==1) move(one,three);
  else
  {hanoi(n-1,one,three,two);
   move(one,three);
   hanoi(n-1,two,one,three);
  }
}
 
void move(char x,char y)
 {cout<<x<<"-->"<<y<<endl;}
