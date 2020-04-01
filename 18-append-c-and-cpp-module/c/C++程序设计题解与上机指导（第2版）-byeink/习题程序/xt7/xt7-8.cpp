#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
int n;     
student *del(student *head,long num)
{student *p1,*p2;
 if (head==NULL)                    //是空表
{cout<<"list null!"<<endl; return(head);}
    p1=head;                          //使p1指向第一个结点
    while(num!=p1->num && p1->next!=NULL) //p1指向的不是所要找的结点且后面还有结点
{p2=p1; p1=p1->next;}                 //p1后移一个结点
if(num==p1->num)                        //找到了
{if(p1==head) head=p1->next;   //若p1指向的是首结点，把第二个结点地址赋予head
 else p2->next=p1->next;    //否则将下一结点地址赋给前一结点地址
 cout<<"delete:"<<num<<endl;
n=n-1;
}
else cout<<"cannot find "<<num;     //找不到该结点
return(head);
}
               
