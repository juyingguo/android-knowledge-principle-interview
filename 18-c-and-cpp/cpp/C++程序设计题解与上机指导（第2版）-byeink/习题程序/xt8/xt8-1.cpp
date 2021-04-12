#include <iostream>
using namespace std;
class Time
 {public:                    //成员改为公用的
    int hour;
    int minute;
    int sec;
  };
Time t;
void set_time(void)          //在main函数之前定义
 {
  cin>>t.hour;
  cin>>t.minute;
  cin>>t.sec;
 }
 
void show_time(void)         //在main函数之前定义
 {
  cout<<t.hour<<":"<<t.minute<<":"<<t.sec<<endl;
 }

int main()
{set_time();
 show_time();
 return 0; 
}


  