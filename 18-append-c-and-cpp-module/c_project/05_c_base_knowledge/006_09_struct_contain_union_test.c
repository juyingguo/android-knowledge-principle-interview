/***
https://blog.csdn.net/weixin_40997830/article/details/89402974

��������һ��ı����Ӧ�ý��٣��ڵ�Ƭ����Ӧ�ý϶ࡣ���� PC ��������ʹ�õ���һ��ʵ���ǣ� 
����һ�Ź���ѧ����Ϣ�ͽ�ʦ��Ϣ�ı��ѧ����Ϣ������������š��Ա�ְҵ��������
��ʦ����Ϣ������������š��Ա�ְҵ����ѧ��Ŀ���뿴����ı��

f �� m �ֱ��ʾŮ�Ժ����ԣ�s ��ʾѧ����t ��ʾ��ʦ�����Կ�����ѧ���ͽ�ʦ�������������ǲ�ͬ�ġ�
����Ҫ�����Щ��Ϣ����ͬһ������У�����Ƴ���������Ա��ϢȻ�������

�����ÿ���˵���Ϣ������һ���ṹ������Ļ�����ô��ʦ��ѧ����ǰ 4 ����Ա������һ���ģ�
�� 5 ����Ա���������� score ���� course������ 4 ����Ա������ֵ�� s ��ʱ�򣬵� 5 ����Ա�������� score��
���� 4 ����Ա������ֵ�� t ��ʱ�򣬵� 5 ����Ա�������� course��

��������ķ��������ǿ������һ������������Ľṹ�壬�뿴����Ĵ��룺
**/	
#include <stdio.h>

#include <stdlib.h>

#define TOTAL 2 //��Ա����

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

 //������Ա��Ϣ

 for(i=0; i<TOTAL; i++){

  printf("Input info: ");

  scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));

  if(bodys[i].profession == 's'){ //�����ѧ��

   scanf("%f", &bodys[i].sc.score);

  }else{ //�������ʦ

   scanf("%s", bodys[i].sc.course);

  }

  fflush(stdin);

 }

 //�����Ա��Ϣ

 printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");

 for(i=0; i<TOTAL; i++){

  if(bodys[i].profession == 's'){ //�����ѧ��

   printf("%s\t%d\t%c\t%c\t\t%f\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.score);

  }else{ //�������ʦ

   printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession, bodys[i].sc.course);

  }

 }

 return 0;

}
