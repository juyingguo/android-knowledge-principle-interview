#include <iostream>
using namespace std;
class Time
 {public:
   Time()
   {hour=0;
    minute=0;
    sec=0;
   }  
   void set_time();
   void show_time();
  private:
   int hour;
   int minute;
   int sec;
 };

void Time::set_time()
{cin>>hour;
 cin>>minute;
 cin>>sec;
}

void Time::show_time()
 {
  cout<<hour<<":"<<minute<<":"<<sec<<endl;
 }

int main()
 {
  Time t1;
  t1.show_time();
  Time t2;
  t2.show_time();
  return 0;
 }
 
