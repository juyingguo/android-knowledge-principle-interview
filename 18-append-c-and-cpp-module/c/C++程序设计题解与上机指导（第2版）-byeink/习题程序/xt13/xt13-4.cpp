#include <iostream>
#include <fstream>
using namespace std;                //VC++ 6.0Ҫ����
//fun1�����Ӽ�������20���������ֱ��������������ļ���

void fun1()
{int a[10];
 ofstream outfile1("f1.dat"),outfile2("f2.dat");  //�ֱ��������ļ�������
 if(!outfile1)                        //����f1.dat�Ƿ�ɹ�
  {cerr<<"open f1.dat error!"<<endl;
   exit(1);
  }
 if(!outfile2)                        //����f2.dat�Ƿ�ɹ�
  {cerr<<"open f2.dat error!"<<endl;
   exit(1);
  } 
 cout<<"enter 10 integer numbers:"<<endl;
 for(int i=0;i<10;i++)          //����10������ŵ�f1.dat�ļ���
  {cin>>a[i];
   outfile1<<a[i]<<" ";}
  cout<<"enter 10 integer numbers:"<<endl;
 for(i=0;i<10;i++)           //����10������ŵ�f2.dat�ļ���
  {cin>>a[i];
   outfile2<<a[i]<<" ";}
 outfile1.close();               //�ر�f1.dat�ļ�
 outfile2.close();               //�ر�f2.dat�ļ�
}

//��f1,dat����10������Ȼ���ŵ�f2.dat�ļ�ԭ�����ݵĺ���
void fun2()
{ifstream infile("f1.dat");       //f1.dat��Ϊ�����ļ�
 if(!infile)
  {cerr<<"open f1.dat error!"<<endl;
   exit(1);
  }
  ofstream outfile("f2.dat",ios::app); 
 //f2.dat��Ϊ����ļ����ļ�ָ��ָ���ļ�β������д������ݷ���ԭ�����ݵĺ���
  if(!outfile)
   {cerr<<"open f2.dat error!"<<endl;
   exit(1);
  }
  int a;
  for(int i=0;i<10;i++)
   {infile>>a;           //�����ļ�f2.dat����һ������
    outfile<<a<<" ";     //��������ŵ�f2.dat��
   }
  infile.close();
  outfile.close();
 }

//��f2.dat�ж���20�������������ǰ���С�����˳���ŵ�f2.dat 
void fun3()
{ifstream infile("f2.dat"); //���������ļ���infile�������뷽ʽ��f2.dat 
 if(!infile)
  {cerr<<"open f2.dat error!"<<endl;
   exit(1);
  }
 int a[20];
 int i,j,t;
 for(i=0;i<20;i++)      
  infile>>a[i];        //�Ӵ����ļ�f2.dat����20������������a��
 for(i=0;i<19;i++)     //�����ݷ���20��������
   for(j=0;j<19-i;j++)
      if(a[j]>a[j+1])
        {t=a[j];a[j]=a[j+1];a[j+1]=t;}
  infile.close();                //�ر������ļ�f2.dat
  ofstream outfile("f2.dat",ios::out);
// f2.dat��Ϊ����ļ����ļ���ԭ������ɾ��
  if(!outfile)
   {cerr<<"open f2.dat error!"<<endl;
    exit(1);}
cout<<"data in f2.dat:"<<endl;
  for( i=0;i<20;i++)
    {outfile<<a[i]<<" ";      //��f2.dat����������20����
     cout<<a[i]<<" ";}        //ͬʱ�������ʾ��
  cout<<endl;
  outfile.close();
}

int main()
{fun1();                     //�ֱ����3������
 fun2();
 fun3();
 return 0;
}
