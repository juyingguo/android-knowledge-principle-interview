#include <iostream>
using namespace std;
struct 
     {int year;
     int month;
     int day;
	 }date;
 int main()
    {int i,days;
     int day_tab[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
     cout<<"input year,month,day:";
     cin>>date.year>>date.month>>date.day;
     days=0;
     for (i=1;i<date.month;i++)
       days+=day_tab[i];
     days+=date.day;
     if ((date.year%4==0 && date.year%100!=0 || date.year%400==0) && date.month>=3)
       days+=1;
     cout<<date.month<<"/"<<date.day<<" is the "<<days
	   <<"th day in "<<date.year<<"."<<endl;
    return 0;
}
