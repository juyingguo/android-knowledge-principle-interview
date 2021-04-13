#include<stdio.h>
#include<stdlib.h>

void straight_insertion_sort(int array_to_sort[],int n);
void print_array(int arr[],int n);

#define N 5 

/**
打印数组 
*/
void print_array(int arr[],int n)//n为数组a的元素个数
{
	// 先定义int i。再使用。 
	int i;
    for(i=0; i<n; i++){
    	 printf("%d ", arr[i]);
    }

    printf("\n"); 
}

void  straight_insertion_sort(int array_to_sort[],int n){
	int insert_num;//要插入的数
	int i;
    for(i=1; i<n; i++){//排序多少次，第一个数不用排序
    	insert_num = array_to_sort[i];
    	int j = i - 1;//前面已经排好序的序列数组索引最大值。
    	while(j>= 0 && array_to_sort[j] > insert_num){//从后往前循环，将大于insertNum的数向后移动
			array_to_sort[j+ 1] = array_to_sort[j];//j 位元素大于insertNum, j 以后元素都往后移动一格
			j-- ;
			
    	} 
    	array_to_sort[j + 1] = insert_num;//比较到第j 位时 小于 insertNum ，所以insertNum 应该放在 j+1 位
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


