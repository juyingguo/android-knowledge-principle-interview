#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 student *next;
};    
                    //����nΪȫ�ֱ��������ļ�ģ���и���������ʹ����
student *creat(void)     //���庯�����˺�������һ��ָ������ͷ��ָ��
{student *head;
 student *p1,*p2;
 int n=0;
 p1=p2=new student;       //����һ���µ�Ԫ����ʹp1,p2ָ����
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



