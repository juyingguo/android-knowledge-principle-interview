//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//��Ŀ�������ѧ����ÿ��ѧ����3�ſεĳɼ����Ӽ��������������ݣ�����ѧ���ţ����������ſγɼ����������ƽ���ɼ���
//��ԭ�е����ݺͼ������ƽ����������ڴ����ļ�"stud"�С�
 
#include<stdio.h>
#include<stdlib.h>
#define INPUT_NUM 1

typedef struct{
    int ID;
    int math;
    int English;
    int C;
    int avargrade;
    char name[20];
}Stu;
int main()
{
    FILE*fp;
    Stu stu[5];
    int i,avargrade=0;
    printf("������%d��ͬѧ����Ϣ��ѧ���ţ�������3�ųɼ�:\n",INPUT_NUM);
    for(i=0;i<INPUT_NUM;i++)
    {
        scanf("%d %s %d %d %d",&(stu[i].ID),stu[i].name,&(stu[i].math),&(stu[i].English),&(stu[i].C));
        stu[i].avargrade=(stu[i].math+stu[i].English+stu[i].C)/3;
    }
    
    if((fp=fopen("I:\\testonly\\stud.txt","a+"))==NULL)//stud.txt �뵱ǰ������ͬһĿ¼�¡�I:/testonly/stud.txt ��I�̷��� ������ I:\\testonly\\stud.txt 
    {
        printf("error :cannot open file!\n");
        exit(0);
    }
    for(i=0;i<INPUT_NUM;i++)
        fprintf(fp,"%d %s %d %d %d %d\n",stu[i].ID,stu[i].name,stu[i].math,stu[i].English,
                stu[i].C,stu[i].avargrade);
    
    fclose(fp);
    // system("pause");
    return 0;
} 
