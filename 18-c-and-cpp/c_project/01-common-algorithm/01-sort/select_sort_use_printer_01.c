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
//ѡ������ʵ��
void select_sort_by_printer(int *p,int n)//nΪԪ�ظ���
{
    //����N-1��ѡ��
    int i ,j;
    for(i=0; i<n; i++)
    {
		
        int min_index = i; 
        //�ҳ���iС�������ڵ�λ��
        for(j=i+1; j<n; j++)
        {
            if(*(p + j) < *(p + min_index))
            {
                min_index = j;
            }
        }

        //����iС���������ڵ�i��λ�ã�����պã��Ͳ��ý���
        if( i != min_index)
        {
            int temp = *(p + i);
            *(p + i) = *(p + min_index);
            *(p + min_index) = temp;
        }
        
        
    }
}
/**
��ӡ����
*/
void print_array_by_printer(int *p,int n)//nΪԪ�ظ���
{
	// �ȶ���int i����ʹ�á� 
	int i;
    for(i=0; i<n; i++){
    	 printf("%d ", *(p + i));
    }

    printf("\n");
}
int  main()
{
    int array_test[N] = {32,43,23,13,5};
    printf("******** raw array ... \n");
    print_array_by_printer(array_test,N); 
	
    select_sort_by_printer(array_test, N);
    printf("******** select sort after ... \n");
    print_array_by_printer(array_test,N); 


    system("pause");
    return 0;

}
