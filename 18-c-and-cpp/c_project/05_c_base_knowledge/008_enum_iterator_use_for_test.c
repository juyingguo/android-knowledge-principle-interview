#include<stdio.h>

enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
int main()
{
    // ����ö��Ԫ��
    for (day = MON; day <= SUN; day++) {
        printf("ö��Ԫ�أ�%d \n", day);
    }
}
