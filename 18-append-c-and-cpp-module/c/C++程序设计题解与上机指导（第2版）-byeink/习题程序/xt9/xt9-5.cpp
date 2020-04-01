#include <iostream>
using namespace std;
class Student
 {public:
   Student(int n,float s):num(n),score(s){}
   int num;
   float score;
 };

void main()
{Student stud[5]={
  Student(101,78.5),Student(102,85.5),Student(103,98.5),
  Student(104,100.0),Student(105,95.5)};
 void max(Student* );
 Student *p=&stud[0];
 max(p);
 }
 
void max(Student *arr)
{float max_score=arr[0].score;
 int k=0;
 for(int i=1;i<5;i++)
   if(arr[i].score>max_score) {max_score=arr[i].score;k=i;}
 cout<<arr[k].num<<" "<<max_score<<endl;
}
   
