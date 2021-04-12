#include<stdio.h>
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
