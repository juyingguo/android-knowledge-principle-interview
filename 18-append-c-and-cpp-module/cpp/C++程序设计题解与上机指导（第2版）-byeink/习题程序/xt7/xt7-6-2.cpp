#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
                    //定义n为全局变量，本文件模块中各函数均可使用它
student *creat(void)     //定义函数。此函数带回一个指向链表头的指针
{student *head;
 student *p1,*p2;
 int n=0;
 p1=p2=new student;       //开辟一个新单元，并使p1,p2指向它
cin>>p1->num>>p1->score;
head=NULL;
while(p1->num!=0)
{n=n+1;
 if(n==1) head=p1;
 else p2->next=p1;
 p2=p1;
 p1=new student;
 cin>>p1->num>>p1->score;
}
p2->next=NULL;
return(head);
}    



