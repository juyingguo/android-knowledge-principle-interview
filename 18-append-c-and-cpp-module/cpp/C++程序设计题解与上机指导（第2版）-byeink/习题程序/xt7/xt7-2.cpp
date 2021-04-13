#include <iostream>
using namespace std;
struct y_m_d
     {int year;
     int month;
     int day;
	 };
 int main()
 {y_m_d date;
  int days(int,int,int);                     /* 对days函数的声明 */
  int day_sum;
  cout<<"input year,month,day:";
  cin>>date.year>>date.month>>date.day;
  day_sum=days(date.year,date.month,date.day);
  cout<<date.month<<"/"<<date.day<<" is the "<<day_sum
	  <<"th day in "<<date.year<<endl;
  return 0;
  }

int days(int year,int month,int day)        /* 定义days函数 */
{int day_sum,i;
 int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 day_sum=0;
 for (i=1;i<month;i++)
   day_sum+=day_tab[i];
 day_sum+=day;
 if ((year%4==0 && year%100!=0 || year%4==0) && month>=3)
     day_sum+=1;
 return(day_sum);
}
