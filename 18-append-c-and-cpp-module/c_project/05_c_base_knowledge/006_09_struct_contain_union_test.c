/***
https://blog.csdn.net/weixin_40997830/article/details/89402974

共用体在一般的编程中应用较少，在单片机中应用较多。对于 PC 机，经常使用到的一个实例是： 
现有一张关于学生信息和教师信息的表格。学生信息包括姓名、编号、性别、职业、分数，
教师的信息包括姓名、编号、性别、职业、教学科目。请看下面的表格：

f 和 m 分别表示女性和男性，s 表示学生，t 表示教师。可以看出，学生和教师所包含的数据是不同的。
现在要求把这些信息放在同一个表格中，并设计程序输入人员信息然后输出。

如果把每个人的信息都看作一个结构体变量的话，那么教师和学生的前 4 个成员变量是一样的，
第 5 个成员变量可能是 score 或者 course。当第 4 个成员变量的值是 s 的时候，第 5 个成员变量就是 score；
当第 4 个成员变量的值是 t 的时候，第 5 个成员变量就是 course。

经过上面的分析，我们可以设计一个包含共用体的结构体，请看下面的代码：
**/	
#include <stdio.h>

#include <stdlib.h>

#define TOTAL 2 //人员总数

struct{

 char name[20];

 int num;

 char sex;

 char profession;

 union{

  float score;

  char course[20];

 } sc;

} bodys[TOTAL];

int main(){

 int i;

 //输入人员信息

 for(i=0; i<TOTAL; i++){

  printf("Input info: ");

  scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));

  if(bodys[i].profession == 's'){ //如果是学生

   scanf("%f", &bodys[i].sc.score);

  }else{ //如果是老师

   scanf("%s", bodys[i].sc.course);

  }

  fflush(stdin);

 }

 //输出人员信息

 printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");

 for(i=0; i<TOTAL; i++){

  if(bodys[i].profession == 's'){ //如果是学生

   printf("%s\t%d\t%c\t%c\t\t%f\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.score);

  }else{ //如果是老师

   printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course);

  }

 }

 return 0;

}
