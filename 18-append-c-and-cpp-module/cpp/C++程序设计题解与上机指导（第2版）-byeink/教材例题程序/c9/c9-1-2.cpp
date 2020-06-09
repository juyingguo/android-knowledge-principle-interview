#include <iostream>
using namespace std;

class Time
 {public:
   Time();
   void show_time();
  private:
   int hour;
   int minute;
   int sec;
 };

Time::Time()
 {
  hour=0;
  minute=0;
  sec=0;
 }

int main()
 {
  Time t1;
  t1.show_time();
  Time t2;
  t2.show_time();
  return 0;
 }
 
void Time::show_time()
 {
  cout<<hour<<":"<<minute<<":"<<sec<<endl;
 }
 
 
