#include<stdio.h>
#include<stdlib.h>
#include "../../include/common_array_util.h"

#define N 5

void bubble_sort(int array_to_sort[],int n);
void print_array(int arr[],int n);

void bubble_sort(int array_to_sort[],int n) {
	int i;
    for(i=0; i<n; i++){//排序多少次，第一个数不用排序
    	int j = 0;
		for(j = 0;j< n - i - 1;j ++) {
			if(array_to_sort[j] > array_to_sort[j+ 1]){
				int temp = array_to_sort[j];
				array_to_sort[j] = array_to_sort[j + 1];
				array_to_sort[j + 1] = temp;
			}
		}
    }
} 

int  main()
{
	//const int N = 5; 
	
    int array_test[N] = {32,43,23,13,7};
    printf("******** raw array ... \n");
    print_array(array_test,N); 
	
    bubble_sort(array_test, N);
    printf("******** select sort after ... \n");
    print_array(array_test,N); 


    system("pause");
    return 0;

}
