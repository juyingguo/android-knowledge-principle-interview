#include<stdio.h>
#include<stdlib.h>

void straight_insertion_sort(int array_to_sort[],int n);
void print_array(int arr[],int n);

#define N 5 

/**
��ӡ���� 
*/
void print_array(int arr[],int n)//nΪ����a��Ԫ�ظ���
{
	// �ȶ���int i����ʹ�á� 
	int i;
    for(i=0; i<n; i++){
    	 printf("%d ", arr[i]);
    }

    printf("\n"); 
}

void  straight_insertion_sort(int array_to_sort[],int n){
	int insert_num;//Ҫ�������
	int i;
    for(i=1; i<n; i++){//������ٴΣ���һ������������
    	insert_num = array_to_sort[i];
    	int j = i - 1;//ǰ���Ѿ��ź�������������������ֵ��
    	while(j>= 0 && array_to_sort[j] > insert_num){//�Ӻ���ǰѭ����������insertNum��������ƶ�
			array_to_sort[j+ 1] = array_to_sort[j];//j λԪ�ش���insertNum, j �Ժ�Ԫ�ض������ƶ�һ��
			j-- ;
			
    	} 
    	array_to_sort[j + 1] = insert_num;//�Ƚϵ���j λʱ С�� insertNum ������insertNum Ӧ�÷��� j+1 λ
    }
	
}

int  main()
{
    int array_test[N] = {32,43,23,13,5};
    printf("******** raw array ... \n");
    print_array(array_test,N); 
	
    straight_insertion_sort(array_test, N);
    printf("******** select sort after ... \n");
    print_array(array_test,N); 


    system("pause");
    return 0;

}


