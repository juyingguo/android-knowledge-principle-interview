
/**顺序线性表的实现**/

#include<stdio.h>
#include<malloc.h>
#define OVERFLOW_ERROR 0
#define ERROR 1
#define OK 2
/*线性表的初始大小*/
#define LIST_INIT_SIZE 100
/*线性表每次的增量*/
#define LIST_INCREMENT 10

/*定义顺序线性表的结构体*/
typedef struct{
    int *elem;//基址指针
    int length;//当前数组长度
    int listsize;//数组的大小
}Sqlist;


/*初始化线性表*/
int InitList_Sq(Sqlist *L){

    L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));

    if(!L->elem){
        exit(OVERFLOW_ERROR);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}


/*向线性表第position个位置前插入元素*/
int InsertList_Sq(Sqlist *L,int position,int insert_elem){

    //判断插入的位置是否合法
    if(position<1 || position>L->length+1){
        return ERROR;
    }
    //判断当前的数组大小是否超过了已申请到的存储空间
    if(L->length>= L->listsize){
        int *newbase = (int *)realloc(L->elem,(L->listsize + LIST_INCREMENT)*sizeof(int));
        //判断是否重新申请到了空间
        if(!newbase){
            exit(OVERFLOW_ERROR);
        }
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }
    //记录要插入的位置
    int *insert_pointer = &(L->elem[position-1]);//最后一个元素的指针

    //将要插入位置后的元素后移
    int *temp= &(L->elem[L->length-1]);//对于L->length = 0时的情况，下标为负数，可以取地址，地址小于L->elem[0]的地址。
    printf("InsertList_Sq,insert_pointer = %x\n",insert_pointer);
    printf("InsertList_Sq,temp = %x\n",temp);
    printf("InsertList_Sq,L->length = %d\n",L->length);
//    printf("InsertList_Sq,(temp >= insert_elem) = %d\n",(temp >= insert_elem));
    int i = 0;
//    for(temp;temp>=insert_pointer;temp){ // 原始代码，造成死循环，比如有两个元素，此时在第二个元素位置插入。
    for(temp;temp>= insert_pointer;temp --){//比较地址
        i++;
        printf("InsertList_Sq,i = %d\n",i);
        *(temp+1) = (*temp);
    }
    *insert_pointer = insert_elem;
    ++L->length;
    return OK;
}
/*删除顺序线性表中的第position个元素，并用elem返回其值*/
int ListDelete(Sqlist *L,int position,int *elem){
    //检查position的合法性
    if( (position<1) || (position>L->length) ){
        return ERROR;
    }
    int *delete_pointer = &(L->elem[position-1]);
    *elem = *delete_pointer;//给参数赋值，使用指针
    int *temp = (L->elem + L->length-1);
//    int *temp = &(L->elem[L->length -1]);//效果同 int *temp = (L->elem + L->length-1);

    for(++delete_pointer;delete_pointer<=temp;++delete_pointer){
        *(delete_pointer-1) = *delete_pointer;
    }

    --(L->length);
    return OK;

}

/*获取线性表的当前长度*/
int ListLength_Sq(Sqlist L){
    return L.length;
}

/*主函数*/
int main(){
    void ShowList(Sqlist list);
    Sqlist list;
    //初始化数组
    int init_flag = InitList_Sq(&list);
    //向数组中插入元素
    InsertList_Sq(&list,1,23);
    InsertList_Sq(&list,2,34);
    InsertList_Sq(&list,1,56);

    ShowList(list);

    int elem = 0;
    init_flag = ListDelete(&list,1,&elem);//删除第二个元素
    printf("main,elem = %d\n",elem);
    ShowList(list);
    return 0;
}

void ShowList(Sqlist list){

    int i = 0;
    for(i;i<list.length;i++){
        printf("%d\n",list.elem[i]);
    }
    printf("数组长度为\t%d\n",list.length);
}
