#include<stdio.h>
#include<malloc.h>

#define ElemType int

typedef struct LinkNode{
	ElemType data;
	struct LinkNode *pNext;
}LinkNode;

LinkNode *pHead = NULL;   //单向链表的头指针
LinkNode *pEnd = NULL;    //单向链表的尾指针

//创建单向链表节点
void CreateNode(LinkNode *pNode)
{
	if(NULL != pNode)
	{
		printf("请输入结点数据：");
		scanf("%d", &pNode->data);
	}
	pNode->pNext = NULL;
}


//创建单向链表（带头节点）,可以理解为创建一个空表，创建的链表中只包含一个头结点
void CreateLinkList()
{
        printf("int type storage sizeof(char) = %d:\n",sizeof(char));
        printf("CreateLinkList(),sizeof(int) = %d \n",sizeof(int));
        printf("int type storage sizeof(int) = %d:\n",sizeof(int));
        printf("CreateLinkList(),sizeof(int(*)) = %d \n" ,sizeof(int(*)));
        printf("CreateLinkList(),sizeof(size_t) = %d \n", sizeof(size_t));
        printf("CreateLinkList(),sizeof(LinkNode) = %d \n" ,sizeof(LinkNode));
        printf("CreateLinkList(),sizeof(LinkNode(*)) = %d \n" ,sizeof(LinkNode(*)));

        printf("int type storage sizeof(pHead) = %d:\n",sizeof(pHead));
		LinkNode *pNew = malloc(sizeof(LinkNode));
		pNew->data = NULL;    //头结点不放元素
		pNew->pNext = NULL;

		pHead = pNew;//将头、尾指针都指向头结点
		pEnd = pNew;
		pEnd->pNext = pHead;
		printf("创建链表成功!\n");
}

//添加结点，结点后面依次按顺序添加，注意与后面的插入结点区分开
void AddNode()
{
		LinkNode *pNew = malloc(sizeof(LinkNode));
		CreateNode(pNew);

		pEnd->pNext = pNew;
		pEnd = pNew;
		printf("添加结点成功!\n");
}

//输出单向链表
void ShowLinkList()
{
	if(pHead != pHead->pNext)  //  循环单链表的判断为空的条件不是头结点的指针是否为空，而是它是否等于头指针
	{
		LinkNode *pTemp = pHead->pNext;  //pTemp指针指向首结点，首结点为头结点的下一个结点
		printf("输出的单向链表为：");
		while(NULL != pTemp)
		{
			printf("%d ", pTemp->data);
			pTemp = pTemp->pNext;
		}
	}
	else
	{
		printf("单向链表为空表!\n");
	}
}

//单向链表中查找某个结点
LinkNode* FindNode(ElemType e, LinkNode **ppLast)   //e为查找条件,第二个参数主要是指向所查找节点的前一个结点，方便后面的插入函数的编写，该参数用到了指针的指针。
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pTemp = pHead;
		while(NULL != pTemp)
		{
			if(e == pTemp->data)
			{
				return pTemp;
			}
			if(NULL != ppLast)
			{
				*ppLast = pTemp;
			}
			pTemp = pTemp->pNext;
		}
	}
	return NULL;
}

//修改单向链表某一结点的值
void ModifyNode(ElemType e)
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pNode = FindNode(e, NULL);
		printf("请输入修改后的结点数据：");
		scanf("%d",&pNode->data);
		printf("修改结点数据成功!\n");
	}
}

//单向链表特定位置插入结点
void InsertNode(ElemType e, int nType)   //e为插入点对应的值，nType表示插入的方式，我们规定nType=0为前插，nType=1为后插
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pLast = NULL;   //记录插入位置的前一个结点
		LinkNode *pPos = FindNode(e, &pLast);   //第二个参数是指针的指针，主要是为了能让形参的值改变实参的值，顺利让pLast指针有正确的指向

		LinkNode *pNew = malloc(sizeof(LinkNode));
		CreateNode(pNew);
		if(0 == nType)  //前插
		{
				pLast->pNext = pNew;
				pNew->pNext = pPos;
		}
		else  //后插
		{
				pNew->pNext = pPos->pNext;
				pPos->pNext = pNew;
		}
		printf("插入结点成功!\n");
	}
}


//删除单向链表某一结点
void DeleteNode(ElemType e)
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pLast = NULL;
		LinkNode *pPos = FindNode(e, &pLast);
		if(NULL != pPos)
		{
			pLast->pNext = pPos->pNext;
			free(pPos);   //释放内存空间
			printf("删除结点成功!\n");
		}
		else
		{
			printf("需要删除的结点不存在!");
		}
	}
}

//删除整个单向链表
void ClearLinkList()
{
	if(pHead != pHead->pNext)
	{
		LinkNode *pClear = pHead->pNext;
		LinkNode *pTemp = NULL;

		while(NULL != pClear)
		{
			pTemp = pClear->pNext;
			free(pClear);
			pClear = pTemp;
		}
		pHead->pNext = pHead;
		pEnd->pNext = pHead;
		printf("清空链表成功!\n");
	}
}


int main()
{
	printf("********************************************\n");
	printf("*                  功能菜单                *\n");
	printf("* 1 创建单向链表           2 顺序添加新结点*\n");
	printf("* 3 修改结点               4 查找结点      *\n");
	printf("* 5 任意位置插入结点       6 删除某结点    *\n");
	printf("* 7 清空整个单向链表       8 打印单向链表  *\n");
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
				CreateLinkList();
				break;
			}
		case 2:
			{
				AddNode();
				break;
			}
		case 3:
			{
				int e;
				printf("请输入要修改的结点：");
				scanf("%d", &e);
				ModifyNode(e);
				break;
			}
		case 4:
			{
				break;
			}
		case 5:
			{
				int e, type;
				printf("请输入要插入的位置和插入方式(两个数据之间用空格分开)：");
				scanf("%d %d", &e, &type);
				InsertNode(e, type);
				break;
			}
		case 6:
			{
				int e;
				printf("请输入要删除的结点：");
				scanf("%d", &e);
				DeleteNode(e);
				break;
			}
		case 7:
			{
				ClearLinkList();
				break;
			}
		case 8:
			{
				ShowLinkList();
				break;
			}
		default:
			printf("error");
		}
	}

	return 0;
}
