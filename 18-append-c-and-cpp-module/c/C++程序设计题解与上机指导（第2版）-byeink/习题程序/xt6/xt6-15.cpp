#include <iostream>
using namespace std;
int main()
{void avsco(float *,float *);
 void avcour1(char (*)[10],float *);
 void fali2(char course[5][10],int num[],float *pscore,float aver[4]);
 void good(char course[5][10],int num[4],float *pscore,float aver[4]);
 int i,j,*pnum,num[4];
 float score[4][5],aver[4],*pscore,*paver;
 char course[5][10],(*pcourse)[10];
 cout<<"input course:"<<endl;
 pcourse=course;
 for (i=0;i<5;i++)
   cin>>course[i];
 cout<<"input NO. and scores:"<<endl;
 cout<<"NO.";
 for (i=0;i<5;i++)
   cout<<","<<course[i];
 cout<<endl;
 pscore=&score[0][0];
 pnum=&num[0];
 for (i=0;i<4;i++)
 {cin>>*(pnum+i);
  for (j=0;j<5;j++)
    cin>>*(pscore+5*i+j);
 }
 paver=&aver[0];
 cout<<endl<<endl;              
 avsco(pscore,paver);                  // 求出每个学生的平均成绩 
 avcour1(pcourse,pscore);                // 求出第一门课的平均成绩 
 cout<<endl<<endl;
 fali2(pcourse,pnum,pscore,paver);       // 找出两门课不及格的学生 
 cout<<endl<<endl;
 good(pcourse,pnum,pscore,paver);        // 找出成绩好的学生 
 return 0;
}

void avsco(float *pscore,float *paver)  // 求每个学生的平均成绩的函数
 {int i,j;
  float sum,average;
  for (i=0;i<4;i++)
   {sum=0.0;
    for (j=0;j<5;j++)
      sum=sum+(*(pscore+5*i+j));       //累计每个学生的各科成绩
    average=sum/5;                   //计算平均成绩
    *(paver+i)=average;
   }
}

void avcour1(char (*pcourse)[10],float *pscore)      // 求第一课程的平均成绩的函数 
 {int i;
  float sum,average1;
  sum=0.0;
  for (i=0;i<4;i++)
    sum=sum+(*(pscore+5*i));               //累计每个学生的得分
  average1=sum/4;                        //计算平均成绩
  cout<<"course 1: "<<*pcourse<<",average score:"<<average1<<endl;
}

void fail2(char course[5][10],int num[],float *pscore,float aver[4])  
           // 找两门以上课程不及格的学生的函数 
 {int i,j,k,labe1;
  cout<<"   ==========Student who failed in two courses =======  "<<endl;
  cout<<"NO.   ";
  for (i=0;i<5;i++)
    cout<<course[i]<<"  ";
  cout<<"  average"<<endl;
  for (i=0;i<4;i++)
  {labe1=0;
   for (j=0;j<5;j++)
     if (*(pscore+5*i+j)<60.0) labe1++;
   if (labe1>=2)
    {cout<<num[i]<<"      ";
     for (k=0;k<5;k++)
       cout<<*(pscore+5*i+k)<<"      ";
     cout<<"    "<<aver[i]<<endl;
    }
  }
}

void good(char course[5][10],int num[4],float *pscore,float aver[4])
   // 找成绩优秀学生(全部课程成绩在85分以上或平均成绩在90分以上)的函数 
 {int i,j,k,n;
  cout<<"    ======Students whose score is good======"<<endl;
  cout<<"NO.   ";
  for (i=0;i<5;i++)
    cout<<course[i]<<"  ";
  cout<<"  average"<<endl;
  for (i=0;i<4;i++)
   {n=0;
    for (j=0;j<5;j++)
      if (*(pscore+5*i+j)>85.0) n++;
    if ((n==5)||(aver[i]>=90))
     {cout<<num[i]<<"      ";
      for (k=0;k<5;k++)
        cout<<*(pscore+5*i+k)<<"      ";
      cout<<"    "<<aver[i]<<endl;
     }
 }
}

	
