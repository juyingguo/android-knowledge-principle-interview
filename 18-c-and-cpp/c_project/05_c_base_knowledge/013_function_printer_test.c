#include <stdio.h>
 
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main(void)
{
    /* p �Ǻ���ָ�� */
    int (* p)(int, int) = & max; // &����ʡ��
    int a, b, c, d;
 
    printf("��������������:");
    scanf("%d %d %d", & a, & b, & c);
 
    /* ��ֱ�ӵ��ú����ȼۣ�d = max(max(a, b), c) */
    d = p(p(a, b), c); 
 
    printf("����������: %d\n", d);
 
    return 0;
}
