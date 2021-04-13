#include <iostream>
#include <iomanip>
using namespace std;
const int n=10;
struct student
{ char num[6];
  char name[8];
  int score[4];
  float avr;
} stu[n];

int main()
{ int i,j,max,maxi,sum;
  float average;
  for (i=0;i<n;i++)
    {cout<<"input scores of student "<<i+1<<endl;;
     cout<<"NO.:";
     cin>>stu[i].num;
     cout<<"name:";
     cin>>stu[i].name;
     for (j=0;j<3;j++)
       {cout<<"score "<<j+1<<":";
        cin>>stu[i].score[j];
       }
	 cout<<endl;
    }
  average=0;
  max=0;
  maxi=0;
  for (i=0;i<n;i++)
    {sum=0;
     for (j=0;j<3;j++)
       sum+=stu[i].score[j];
     stu[i].avr=sum/3.0;
     average+=stu[i].avr;
     if (sum>max)
      {max=sum;
       maxi=i;
      }
    }
  average/=n;
  cout<<"     NO.        name      score1    score2    score3    average"<<endl;
  for (i=0;i<n;i++)
    {cout<<setw(8)<<stu[i].num<<"  "<<setw(10)<<stu[i].name<<"       ";
     for (j=0;j<3;j++)
       cout<<setw(3)<<stu[i].score[j]<<"       ";
     cout<<stu[i].avr<<endl;
    }
    cout<<"average="<<average<<endl;
    cout<<"The highest score is :"<<stu[maxi].name<<", score total:"<<max<<endl;
  return 0;
 }



