#include <iostream>
#include <string>
using namespace std;
int main()
 {void change(string &,string &);
  string str1="                 ",
	     str2="                 ",
		 str3="                 ";
  char *p1=&str1[0],*p2=&str2[0],*p3=&str3[0];
  cout<<"input three line:"<<endl;
  gets(p1);
  gets(p2);
  gets(p3);
  if(str1>str2)change(str1,str2);
  if(str1>str3)change(str1,str3);
  if(str2>str3)change(str2,str3);
  cout<<endl<<"Now,the order is:"<<endl;
  cout<<str1<<endl<<str2<<endl<<str3<<endl;
  return 0;
 }
 void change(string &st1,string &st2)          /* ½»»»Á½¸ö×Ö·û´® */
 {string st;
  st=st1;st1=st2;st2=st;
 }



 
