#include<stdio.h>
#include<stdlib.h>

void select_sort(int a[],int n);
void print_array(int a[],int n);

#define N 5 
#define N_MAX_NUM_TEST 10

//ѡ������ʵ��
void select_sort(int a[],int n)//nΪ����a��Ԫ�ظ���
{
    //����N-1��ѡ��
    int i ,j;
    for(i=0; i<n; i++)
    {		

        int min_index = i; 
        //�ҳ���iС�������ڵ�λ��
        for(j=i+1; j<n; j++)
        {
            if(a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        //����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý���
        if( i != min_index)
        {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        
        
    }
}
/**
��ӡ���� 
*/
void print_array(int a[],int n)//nΪ����a��Ԫ�ظ���
{
	// �ȶ���int i����ʹ�á� 
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
