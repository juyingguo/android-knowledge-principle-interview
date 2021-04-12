#include <stdlib.h>  
#include <stdio.h>
 
// �ص�����
void populate_array(int *array, size_t arraySize, int (*p)(void))
{
	size_t i=0;
    for (i; i<arraySize; i++)
        array[i] = p();
}
 
// ��ȡ���ֵ
int getNextRandomValue(void)
{
    return rand();
}
 
int main(void)
{
    int myarray[3];
    populate_array(myarray, 3, getNextRandomValue);
    int i;
    for(i = 0; i < 3; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}
