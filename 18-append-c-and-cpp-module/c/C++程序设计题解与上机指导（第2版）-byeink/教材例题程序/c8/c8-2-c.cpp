#include <iostream>
using namespace std;
class Time
 {public:
  int hour;
  int minute;
  int sec;
 };
int main()
 {
  void set_time(Time&,int hour=0,int minute=0,int sec=0);
  void show_time(Time&);
  Time t1;
  set_time(t1,12,23,34);
  show_time(t1);
  Time t2;
  set_time(t2);
  show_time(t2);
  return 0;
 }
 
void set_time(Time& t,int hour=9,int minute=30,int sec=0)
 {
  t.hour=hour;
  t.minute=minute;
  t.sec=sec;
 }
 
void show_time(Time& t)
 {
  cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
 }
 
 
