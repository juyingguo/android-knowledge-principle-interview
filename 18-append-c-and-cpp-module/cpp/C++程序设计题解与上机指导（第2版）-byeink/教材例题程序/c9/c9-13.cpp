#include <iostream>
using namespace std;
class Date;
class Time
 {public:
   Time(int,int,int);
   void display(const Date&);
  private:
   int hour;
   int minute;
   int sec;
 };

 class Date
 {public:
   Date(int,int,int);
   friend void Time::display(const Date &);
  private:
   int month;
   int day;
   int year;
 };

 Time::Time(int h,int m,int s)
 {hour=h;
  minute=m;
  sec=s;
 }

void Time::display(const Date &da)
 {cout<<da.month<<"/"<<da.day<<"/"<<da.year<<endl;
  cout<<hour<<":"<<minute<<":"<<sec<<endl;
 }
 
 
Date::Date(int m,int d,int y)
 {month=m;
  day=d;
  year=y;
 }
   
int main()
{Time t1(10,13,56);
 Date d1(12,25,2004);
 t1.display(d1);
 return 0;
}
 

