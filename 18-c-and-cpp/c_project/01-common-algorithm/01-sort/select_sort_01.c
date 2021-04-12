#include<stdio.h>
#include<stdlib.h>

void select_sort(int a[],int n);
void print_array(int a[],int n);

#define N 5 
#define N_MAX_NUM_TEST 10

//选择排序实现
void select_sort(int a[],int n)//n为数组a的元素个数
{
    //进行N-1轮选择
    int i ,j;
    for(i=0; i<n; i++)
    {		

        int min_index = i; 
        //找出第i小的数所在的位置
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        //将第i小的数，放在第i个位置；如果刚好，就不用交换
        if( i != min_index)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        
        
    }
}
/**
打印数组 
*/
void print_array(int a[],int n)//n为数组a的元素个数
{
	// 先定义int i。再使用。 
	int i;
    for(i=0; i<n; i++){
    	 printf("%d ", a[i]);
    }

    printf("\n"); 
}
int  main()
{
    int array_test[N] = {32,43,23,13,5};
    printf("******** raw array ... \n");
    print_array(array_test,N); 
	
    select_sort(array_test, N);
    printf("******** select sort after ... \n");
    print_array(array_test,N); 


    system("pause");
    return 0;

}
