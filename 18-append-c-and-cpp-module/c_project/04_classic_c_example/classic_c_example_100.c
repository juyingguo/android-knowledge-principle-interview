//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//题目：有五个学生，每个学生有3门课的成绩，从键盘输入以上数据（包括学生号，姓名，三门课成绩），计算出平均成绩，
//况原有的数据和计算出的平均分数存放在磁盘文件"stud"中。
 
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
    printf("请输入%d个同学的信息：学生号，姓名，3门成绩:\n",INPUT_NUM);
    for(i=0;i<INPUT_NUM;i++)
    {
        scanf("%d %s %d %d %d",&(stu[i].ID),stu[i].name,&(stu[i].math),&(stu[i].English),&(stu[i].C));
        stu[i].avargrade=(stu[i].math+stu[i].English+stu[i].C)/3;
    }
    
    if((fp=fopen("I:\\testonly\\stud.txt","a+"))==NULL)//stud.txt 与当前程序在同一目录下。I:/testonly/stud.txt 在I盘符下 。或者 I:\\testonly\\stud.txt 
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
