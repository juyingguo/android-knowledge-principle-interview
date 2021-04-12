#include <iostream>
using namespace std;
class Time
 {public:
  int hour;
  int minute;
  int sec;
 };
int main()
 {Time t1;
  cin>>t1.hour;
  cin>>t1.minute;
  cin>>t1.sec;
  cout<<t1.hour<<":"<<t1.minute<<":"<<t1.sec<<endl;
  Time t2;
  cin>>t2.hour;
  cin>>t2.minute;
  cin>>t2.sec;
  cout<<t2.hour<<":"<<t2.minute<<":"<<t2.sec<<endl;
  return 0;
 }
 
 
