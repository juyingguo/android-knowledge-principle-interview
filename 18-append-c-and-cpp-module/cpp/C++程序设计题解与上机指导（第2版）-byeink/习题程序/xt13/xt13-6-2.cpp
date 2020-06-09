#include <iostream>
#include <strstream>
using namespace std;
struct student
{int num;
 char name[20];
 double score;
};
int main()
{int i;
 student stud[3]={1001,"Li",78,1002,"Wang",89.5,1004,"Fun",90},stud1[3];
 char c[50];
 strstream strio(c,50,ios::in|ios::out);
 for(i=0;i<3;i++)
  strio<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<" ";
 strio<<ends;
 cout<<"array c:"<<endl<<c<<endl<<endl;
 for(i=0;i<3;i++)
  strio>>stud1[i].num>>stud1[i].name>>stud1[i].score;
 cout<<"data from array c to array stud1:"<<endl;
 for(i=0;i<3;i++)
  cout<<stud1[i].num<<" "<<stud1[i].name<<" "<<stud1[i].score<<endl;
 cout<<endl;
 return 0;
}

