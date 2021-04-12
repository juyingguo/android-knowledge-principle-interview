#include <iostream>
#include <strstream>
using namespace std;

struct student
{int num;
 char name[20];
 double score;
};
int main()
{student stud[3]={1001,"Li",78,1002,"Wang",89.5,1004,"Fun",90},stud1[3];
 char c[50];
 int i;
 ostrstream strout(c,50);
 for(i=0;i<3;i++)
  strout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<" ";
 strout<<ends;
 cout<<"array c:"<<endl<<c<<endl<<endl;
 istrstream strin(c,50);
 for(i=0;i<3;i++)
  strin>>stud1[i].num>>stud1[i].name>>stud1[i].score;
 cout<<"data from array c to array stud1:"<<endl;
 for(i=0;i<3;i++)
  cout<<stud1[i].num<<" "<<stud1[i].name<<" "<<stud1[i].score<<endl;
 cout<<endl;
 return 0;
}

