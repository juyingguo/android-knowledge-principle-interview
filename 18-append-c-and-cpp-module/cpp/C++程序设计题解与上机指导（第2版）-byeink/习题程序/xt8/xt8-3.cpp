#include <iostream>
using namespace std;
class Time
  {public:
    void set_time(void);
    void show_time(void);
   private:
    int hour;
    int minute;
    int sec;
  };
  
void Time::set_time(void)
  {cin>>hour;
   cin>>minute;
   cin>>sec;
  }
     
void Time::show_time(void)
{cout<<hour<<":"<<minute<<":"<<sec<<endl;}

Time t;
int main()
{ t.set_time();
  t.show_time();
  return 0;
}  
