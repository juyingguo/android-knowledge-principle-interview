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
 avsco(pscore,paver);                  // ���ÿ��ѧ����ƽ���ɼ� 
 avcour1(pcourse,pscore);                // �����һ�ſε�ƽ���ɼ� 
 cout<<endl<<endl;
 fali2(pcourse,pnum,pscore,paver);       // �ҳ����ſβ������ѧ�� 
 cout<<endl<<endl;
 good(pcourse,pnum,pscore,paver);        // �ҳ��ɼ��õ�ѧ�� 
 return 0;
}

void avsco(float *pscore,float *paver)  // ��ÿ��ѧ����ƽ���ɼ��ĺ���
 {int i,j;
  float sum,average;
  for (i=0;i<4;i++)
   {sum=0.0;
    for (j=0;j<5;j++)
      sum=sum+(*(pscore+5*i+j));       //�ۼ�ÿ��ѧ���ĸ��Ƴɼ�
    average=sum/5;                   //����ƽ���ɼ�
    *(paver+i)=average;
   }
}

void avcour1(char (*pcourse)[10],float *pscore)      // ���һ�γ̵�ƽ���ɼ��ĺ��� 
 {int i;
  float sum,average1;
  sum=0.0;
  for (i=0;i<4;i++)
    sum=sum+(*(pscore+5*i));               //�ۼ�ÿ��ѧ���ĵ÷�
  average1=sum/4;                        //����ƽ���ɼ�
  cout<<"course 1: "<<*pcourse<<",average score:"<<average1<<endl;
}

void fail2(char course[5][10],int num[],float *pscore,float aver[4])  
           // ���������Ͽγ̲������ѧ���ĺ��� 
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
   // �ҳɼ�����ѧ��(ȫ���γ̳ɼ���85�����ϻ�ƽ���ɼ���90������)�ĺ��� 
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

	
