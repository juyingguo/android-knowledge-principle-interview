#include <iostream>
#include <string>
using namespace std;
struct Person
 { char name[20];
   int count;
 };
int main()
 {Person leader[3]={"Li",0,"Zhang",0,"Fun",0};
  int i,j;
  char leader_name[20];
  for(i=0;i<10;i++)
    {cin>>leader_name;
     for(j=0;j<3;j++)
       if(strcmp(leader_name,leader[j].name)==0) leader[j].count++;
     }
  cout<<endl;
  for(i=0;i<3;i++)
    {cout<<leader[i].name<<":"<<leader[i].count<<endl;}
  return 0;
 }

