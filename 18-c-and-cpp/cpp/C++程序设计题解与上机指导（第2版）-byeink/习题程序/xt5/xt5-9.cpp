#include <iostream>
using namespace std;
int main()
  {int sum_day(int,int);
   int leap(int year);
   int year,month,day,days=0;
   cout<<"input date(year,month,day):";
   cin>>year>>month>>day;
   cout<<year<<"/"<<month<<"/"<<day;
   days=sum_day(month,day);                                   /* ���ú���һ */
   if(leap(year) && month>=3)                                 /* ���ú����� */
     days=days+1;
   cout<<" is the "<<days<<"th day in this year."<<endl;
   return 0;
   }


int sum_day(int month,int day)          //�������� 
  {int i; 
   int day_tab[12]={31,28,31,30,31,30,31,31,30,31,30,31};  
   for (i=0;i<month-1;i++)
      day+=day_tab[i];
   return(day);
  }                    
     
int leap(int year)                     //�ж��Ƿ�Ϊ���� 
 {int leap;
  leap=year%4==0&&year%100!=0||year%400==0;
  return(leap);
 } 

