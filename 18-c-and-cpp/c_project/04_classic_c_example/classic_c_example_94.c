/**
��Ŀ��������Ϸ��
*/

//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
void caizi(void)
{
    int n;
    char begin;
    int count = 1;
    srand((int)time(NULL));
    int m = (rand() % 100) + 1;
    puts("��Ϸ��ʼ������������:");
    while (1)
    {
        scanf("%d", &n);
        if (n == m)
        {
            printf("�����ˣ�ʹ���� %d �Σ�\n", count);
            if (count == 1)
            {
                printf("�����������ˣ�Ĥ��\n");
                getchar();
                printf("���Ѿ��ﵽ��߼��𣬻���Ҫ����Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y')      //�ظ����һ��Ƕ��ѭ��
                {
                    caizi();
                }
                else
                {
                    printf("лл���ټ�!\n");
                }
            }
            else if (count <= 5)
            {
                printf("�������������ˣ��ǳ���\n");
                getchar();
                printf("��Ҫ��ս��߼��𲻣�Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y')
                {
                    caizi();
                }
                else
                {
                    printf("лл���ټ�!\n");
                }
            }
            else if (count <= 10)
            {
                printf("���Ǵ�ʦ�������ˣ�����\n");
                getchar();
                printf("��Ҫ��ս��߼��𲻣�Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y')
                {
                    caizi();
                }
                else
                {
                    printf("лл���ټ�!\n");
                }
            }
            else if (count <= 15)
            {
                printf("������ʯ�������ˣ�ŭ��\n");
                getchar();
                printf("��Ҫ��ս��߼��𲻣�Y/N \n");
                scanf("%c", &begin);
                if (begin == 'Y' || begin == 'y')
                {
                    caizi();
                }
                else
                {
                    printf("лл���ټ�!\n");
                }
            }
            else
            {
                getchar();
                printf("��ļ������д����Ŷ�����棿 Y/N\n");
                scanf("%c",&begin);
                if (begin == 'Y' || begin == 'y')
                {
                    caizi();
                }
                else
                {
                    printf("лл���ټ�!\n");
                }
            }
            break;
        }
        else if (n < m)
        {
            puts("̫С��!");
            puts("��������:");
        }
        else
        {
            puts("̫����!");
            puts("��������:");
        }
        count++;//������
        
        
    }
}
 
 
int main(void)
{
    
    caizi();
    system("pause");
    return 0;
}
