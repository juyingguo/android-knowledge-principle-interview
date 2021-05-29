/* 非循环单链表。
    1.该链表含，头指针、尾指针
    2.添加:求链表的中间节点
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


 typedef struct Node
{
	int data;//数据域，用来存放数据域；
	struct Node *pNext;//定义一个结构体指针，指向下一次个与当前节点数据类型相同的节点
}NODE,*PNODE;  //NODE等价于 struct Node; PNODE等价于struct Node *； 此处用大写是为了与变量区分，可以让人容易变出是个数据类型

PNODE Create_List(void)
{
    printf("Create_List start.\n");

	int len;  //存放链表的长度
	int i;   //循环变量
	int val;//用来临时存放用户输入的结点的值
	PNODE List;
	PNODE pHead=(PNODE)malloc(sizeof(NODE));//分配一个头节点
	if(NULL==pHead)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	else
	{   PNODE pTail=pHead;

        printf("Create_List pHead= %x,pTail = %x\n",pHead,pTail);

		pHead->pNext=NULL;
		printf("Create_List pHead->pNext= %x \n",pHead->pNext);
		printf("Create_List please input the length of list: ");  //需要一个指针始终指向链表的结尾
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
		    PNODE p=(PNODE)malloc(sizeof(NODE));
		    if(NULL==p)
	        {
		        printf("Create_List Memory allocation failure");
		        exit(-1);
	        }
			else
			{
				printf("please input the value of list: ");
				scanf("%d",&val);
				p->data=val;
				pTail->pNext=p;
				p->pNext=NULL;
				pTail=p;
			}
            printf("Create_List i=%d , pHead= %x,pTail = %x\n",i,pHead,pTail);
            printf("Create_List pHead->pNext= %x \n",pHead->pNext);

		}


	}
	return pHead;

}
/**
采用头插法：
链表的第pos有效元素前面插入元素val，首先我们应该找到第pos个元素前面一个元素的位置；
当链表有3个元素时，pos=4，将不会进行插入操作。不管链表有无元素，当pos<=0时，都不允许插入。只有个当pos>=1时才允许插入
1.链表首节点序号为1，依次递增

*/
bool Insert_List(PNODE pHead,int pos,int val)
{
    if(pos < 1){//可以防止用户输入错误
        printf("Insert_List, pos < 1 can't insert.\n");
        return false;
    }
	int i=0;
	PNODE p=pHead;
	while((NULL!=p)&&(i<pos-1))
	{
		p=p->pNext;
		i++;
	}
	if(p==NULL)  //把链表为空的情况考虑进去了；
    {
        printf("Insert_List, pos >= (list length + 2),p==NULL can't insert.\n");
		return false;
    }

	//程序执行到这之后，i=pos-1；p指针指向链表第pos个有效节点的前驱，即指向第pos-1节点；
	PNODE q=(PNODE)malloc(sizeof(NODE));
	q->data=val;
	q->pNext=p->pNext;
	p->pNext=q;

    return true;
}
/**
pos>=1 且pos<=n;pos即为要删除的第几个元素，此时的索引从1开始。
*/
bool Delete_List(PNODE pHead,int pos,int *val)
{
	int i=0;
	PNODE p=pHead;
	while((NULL!=p)&&(i<pos-1))
	{
		p=p->pNext;
		i++;
	}
	if(p==NULL||i>pos-1)  //把链表为空的情况考虑进去了；i>pos-1 可以防止用户输入错误；
		return false;

	//程序执行到这之后，i=pos-1；
	PNODE q=p->pNext;  //q指向待删除的节点；
	*val=q->data;
	p->pNext=q->pNext; //修改链表指针指向；
	free(q);           //释放q所指向节点的内存；
	q=NULL;//千万不可以忘记，否则会出现野指针；
	return true;
}
//链表有效元素的个数
int Length_List(PNODE pHead)
{   int len=0;  //定义变量要记得初始化；
    PNODE p=pHead->pNext;
	while(NULL!=p)
	{
		len++;
		p=p->pNext;
	}

    printf("Length_List len= %d \n",len);
	return len;

}
/**
    遍历链表。打印出值。
*/
void print_List(PNODE pHead)
{   int i=0;  //定义变量要记得初始化；
    PNODE p=pHead->pNext;

	while(NULL!=p)
	{
		i++;
        printf("print_List current node number i=%d , p->data = %d\n",i,p->data);

		p=p->pNext;
	}


}

//对链表中的元素进行排序
void Sort_List(PNODE pHead)
{
	int i,j;
	int temp;
	int len=Length_List(pHead);
	PNODE p,q;//指向链表第一个有效元素

	for(i=0,p=pHead->pNext;i<len-1;i++,p=p->pNext)
	{
		for(j=i+1,q=p->pNext;j<len;j++,q=q->pNext)
		{
			//交换数据
			if(p->data>q->data)
			{
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

/**
    求链表的中间节点。打印出值。
*/
void print_middle_nodes(PNODE pHead)
{   int i=0;  //定义变量要记得初始化；
    int len=Length_List(pHead);
    if(len == 0) {

        printf("print_middle_nodes,list is empty.");
        return;
    }
    PNODE p=pHead->pNext;//p指向首节点
    if(len == 1){
        printf("print_middle_nodes,middle node p->data = %d\n",p->data);
        return;
    }

    int middle_index = 0;
    if(len%2 == 0){
        //偶数
        middle_index = len/2;
        while(NULL!=p)
        {
            i++;
            if(middle_index == i || (middle_index + 1) == i){

                printf("print_middle_nodes middle node(even number) i=%d , p->data = %d\n",i,p->data);
            }
            p=p->pNext;
        }
    }else{
        //奇数
        middle_index = len/2 + 1;
        while(NULL!=p)
        {
            i++;
            if(middle_index == i){

                printf("print_middle_nodes middle node(odd number) i=%d , p->data = %d\n",i,p->data);
                break;
            }
            p=p->pNext;
        }
    }

}


int main(void)
{
//   PNODE list = Create_List();
//   int length_list = Length_List(list);
//   printf("main length_list= %d:\n",length_list);
//
//   print_List(list);
//
//   if(length_list >=2){
//        int delVal = -1;
//        printf("when length_list >=2 delete node of number 2\n");
//        Delete_List(list,2,&delVal);
//
//        length_list = Length_List(list);
//        printf("main current length_list= %d:\n",length_list);
//        printf("delete node it's value is %d\n",delVal);
//
//        print_List(list);
//   }
    PNODE pHead = NULL;

    printf("********************************************\n");
	printf("*                  功能菜单                *\n");
	printf("* 1 创建单向链表         2 任意位置插入结点*\n");
	printf("* 3 打印单向链表个数     4 打印单向链表    *\n");
	printf("* 5 删除某结点           6 链表排序        *\n");
	printf("* 7 求链表的中间节点     8                 *\n");
	printf("* 9                      10 退出           *\n");
	printf("********************************************\n");
	while(1)
	{
		int choice;
		printf("请输入功能序号：");
		scanf("%d" ,&choice);
		switch(choice)
		{
		case 1:
			{
				pHead = Create_List();
				break;
			}
		case 2:
			{
				int pos, val;
				printf("请输入要插入的位置和值(两个数据之间用空格分开)：");
				scanf("%d %d", &pos, &val);
				Insert_List(pHead,pos, val);
				break;
			}
		case 3:
			{

				Length_List(pHead);
				break;
			}
		case 4:
			{
			    print_List(pHead);
				break;
			}
		case 5:
			{
                int pos, val;
				printf("请输入要删除的位置：");
				scanf("%d", &pos);
				Delete_List(pHead,pos, val);
				break;
			}
		case 6:
			{
                Sort_List(pHead);
				break;
			}
		case 7:
			{
                print_middle_nodes(pHead);
				break;
			}
		case 8:
			{

				break;
			}
        case 9:
            {

                break;
            }
        case 10:
            {
                exit(0);
            }
		default:
			printf("error");
		}
	}
   return 0;
}


