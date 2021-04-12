#include <iostream>
using namespace std;
class Time
 {public:
  int hour;
  int minute;
  int sec;
 };
int main()
 { Time t1;
   Time &t2=t1;
   cin>>t2.hour;
   cin>>t2.minute;
   cin>>t1.sec;
   cout<<t1.hour<<":"<<t1.minute<<":"<<t2.sec<<endl;
 }
 
 
