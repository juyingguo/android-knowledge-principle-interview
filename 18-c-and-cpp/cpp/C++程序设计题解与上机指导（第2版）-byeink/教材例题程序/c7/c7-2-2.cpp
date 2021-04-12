#include <iostream>
#include <string>
using namespace std;
struct Person
 { string name;
   int count;
 };
int main()
 {Person leader[3]={"Li",0,"Zhang",0,"Fun",0};
  int i,j;
  string leader_name;
  for(i=0;i<3;i++)
    {cin>>leader_name;
     for(j=0;j<10;j++)
       if(leader_name==leader[j].name) leader[j].count++;
     }
  cout<<endl;
  for(i=0;i<3;i++)
    {cout<<leader[i].name<<":"<<leader[i].count<<endl;}
  return 0;
 }

