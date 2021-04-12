
/**˳�����Ա��ʵ��**/

#include<stdio.h>
#include<malloc.h>
#define OVERFLOW_ERROR 0
#define ERROR 1
#define OK 2
/*���Ա�ĳ�ʼ��С*/
#define LIST_INIT_SIZE 100
/*���Ա�ÿ�ε�����*/
#define LIST_INCREMENT 10

/*����˳�����Ա�Ľṹ��*/
typedef struct{
    int *elem;//��ַָ��
    int length;//��ǰ���鳤��
    int listsize;//����Ĵ�С
}Sqlist;


/*��ʼ�����Ա�*/
int InitList_Sq(Sqlist *L){

    L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));

    if(!L->elem){
        exit(OVERFLOW_ERROR);
    }
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}


/*�����Ա��position��λ��ǰ����Ԫ��*/
int InsertList_Sq(Sqlist *L,int position,int insert_elem){

    //�жϲ����λ���Ƿ�Ϸ�
    if(position<1 || position>L->length+1){
        return ERROR;
    }
    //�жϵ�ǰ�������С�Ƿ񳬹��������뵽�Ĵ洢�ռ�
    if(L->length>= L->listsize){
        int *newbase = (int *)realloc(L->elem,(L->listsize + LIST_INCREMENT)*sizeof(int));
        //�ж��Ƿ��������뵽�˿ռ�
        if(!newbase){
            exit(OVERFLOW_ERROR);
        }
        L->elem = newbase;
        L->listsize += LIST_INCREMENT;
    }
    //��¼Ҫ�����λ��
    int *insert_pointer = &(L->elem[position-1]);//���һ��Ԫ�ص�ָ��

    //��Ҫ����λ�ú��Ԫ�غ���
    int *temp= &(L->elem[L->length-1]);//����L->length = 0ʱ��������±�Ϊ����������ȡ��ַ����ַС��L->elem[0]�ĵ�ַ��
    printf("InsertList_Sq,insert_pointer = %x\n",insert_pointer);
    printf("InsertList_Sq,temp = %x\n",temp);
    printf("InsertList_Sq,L->length = %d\n",L->length);
//    printf("InsertList_Sq,(temp >= insert_elem) = %d\n",(temp >= insert_elem));
    int i = 0;
//    for(temp;temp>=insert_pointer;temp){ // ԭʼ���룬�����ѭ��������������Ԫ�أ���ʱ�ڵڶ���Ԫ��λ�ò��롣
    for(temp;temp>= insert_pointer;temp --){//�Ƚϵ�ַ
        i++;
        printf("InsertList_Sq,i = %d\n",i);
        *(temp+1) = (*temp);
    }
    *insert_pointer = insert_elem;
    ++L->length;
    return OK;
}
/*ɾ��˳�����Ա��еĵ�position��Ԫ�أ�����elem������ֵ*/
int ListDelete(Sqlist *L,int position,int *elem){
    //���position�ĺϷ���
    if( (position<1) || (position>L->length) ){
        return ERROR;
    }
    int *delete_pointer = &(L->elem[position-1]);
    *elem = *delete_pointer;//��������ֵ��ʹ��ָ��
    int *temp = (L->elem + L->length-1);
//    int *temp = &(L->elem[L->length -1]);//Ч��ͬ int *temp = (L->elem + L->length-1);

    for(++delete_pointer;delete_pointer<=temp;++delete_pointer){
        *(delete_pointer-1) = *delete_pointer;
    }

    --(L->length);
    return OK;

}

/*��ȡ���Ա�ĵ�ǰ����*/
int ListLength_Sq(Sqlist L){
    return L.length;
}

/*������*/
int main(){
    void ShowList(Sqlist list);
    Sqlist list;
    //��ʼ������
    int init_flag = InitList_Sq(&list);
    //�������в���Ԫ��
    InsertList_Sq(&list,1,23);
    InsertList_Sq(&list,2,34);
    InsertList_Sq(&list,1,56);

    ShowList(list);

    int elem = 0;
    init_flag = ListDelete(&list,1,&elem);//ɾ���ڶ���Ԫ��
    printf("main,elem = %d\n",elem);
    ShowList(list);
    return 0;
}

void ShowList(Sqlist list){

    int i = 0;
    for(i;i<list.length;i++){
        printf("%d\n",list.elem[i]);
    }
    printf("���鳤��Ϊ\t%d\n",list.length);
}
