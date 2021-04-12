#include <iostream>
using namespace std;
class Time
{public:
   Time(){minute=0;sec=0;}
   Time(int m,int s):minute(m),sec(s){}
   Time operator++();
   void display(){cout<<minute<<":"<<sec<<endl;}
  private:
   int minute;
   int sec;
 };

Time Time::operator++()
{if(++sec>=60)
  {sec-=60;
   ++minute;}
   return *this;
}
   
int main()
{Time time1(34,0);
 for (int i=0;i<61;i++)
	{++time1;
     time1.display();}
 return 0;
}

