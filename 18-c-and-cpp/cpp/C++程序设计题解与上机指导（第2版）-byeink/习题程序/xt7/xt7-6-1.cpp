#include <iostream>
using namespace std;
#define NULL 0     
struct student
{long num;
 float score;
 struct student *next;
};
int main()
 {student a,b,c,*head,*p;
  a.num=10001; a.score=89.5;
  b.num=10003; b.score=90;
  c.num=10007; c.score=85;     //为结点的num和score成员赋值
  head=&a;                      //将结点a的起始地址赋给头指针head
  a.next=&b;                    //将结点b的起始地址赋给a结点的next成员
  b.next=&c;                    //将结点c的起始地址赋给b结点的next成员
  c.next=NULL;                  //c结点的next成员不存放其他结点地址
  p=head;                       //使p指针指向a结点
  do        
   {cout<<p->num<<"  "<<p->score<<endl; //输出p指向的结点的数据
    p=p->next;                                //使p指向下一结点
   }while(p!=NULL);                          //输出完c结点后p的值为NULL
  return 0;
}

