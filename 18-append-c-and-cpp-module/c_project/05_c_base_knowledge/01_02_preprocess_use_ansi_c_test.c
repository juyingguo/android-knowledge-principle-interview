#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**

Ԥ�����
    ANSI C ���������ꡣ�ڱ����������ʹ����Щ�꣬���ǲ���ֱ���޸���ЩԤ����ĺꡣ

    ��	����
    __DATE__	��ǰ���ڣ�һ���� "MMM DD YYYY" ��ʽ��ʾ���ַ�������
    __TIME__	��ǰʱ�䣬һ���� "HH:MM:SS" ��ʽ��ʾ���ַ�������
    __FILE__	��������ǰ�ļ�����һ���ַ���������
    __LINE__	��������ǰ�кţ�һ��ʮ���Ƴ�����
    __STDC__	���������� ANSI ��׼����ʱ������Ϊ 1��


    https://www.runoob.com/cprogramming/c-preprocessors.html
*/
/**
�Ӹ�������·���ļ����л�ȡ��̵��ļ�����
*/
void get_short_file_name(char *desc,char *src){

    char split = '\\';//·��\��Ҫת�塣·����window��Ϊ\����linux��Ϊ/��
   int length = strlen(src);
   printf("file length :%d\n", length);
   int i = 0;
   int last_split_occor_index = -1;
   for(i; i < length; i++){
        if(src[i] == split){
            last_split_occor_index = i;
        }
   }
    printf("last_split_occor_index :%d\n", last_split_occor_index);
   if(last_split_occor_index != -1){

        strncpy(desc, src+last_split_occor_index + 1, length - last_split_occor_index);
   }


}
void * get_short_file_name2(/*char *desc,*/char *src){

    char split = '\\';//·��\��Ҫת�塣·����window��Ϊ\����linux��Ϊ/��
   int length = strlen(src);
   printf("file length :%d\n", length);
   char * dest_short_file_name = (char *) malloc(100);//ʹ��ָ����Ҫ�Լ�����ռ�
   int i = 0;
   int last_split_occor_index = -1;
   for(i; i < length; i++){
        if(src[i] == split){
            last_split_occor_index = i;
        }
   }
    printf("last_split_occor_index :%d\n", last_split_occor_index);
   if(last_split_occor_index != -1){

        strncpy(dest_short_file_name, src+last_split_occor_index + 1, length - last_split_occor_index);
   }
//    free(dest_short_file_name);//��ʱ�ͷſռ䣬���µ����߻�ȡ��������
    return dest_short_file_name;

}
/**
�Ӹ�������·���ļ����л�ȡ��̵��ļ�����
ȫ�������ڳ������н���ʱ�Զ��ͷš�

�����ڶ���������ں����˳�ʱ�Զ��ͷš�
��ȡ������Ϊ�ա�
*/
void * get_short_file_name3(/*char *desc,*/char *src){

    char split = '\\';//·��\��Ҫת�塣·����window��Ϊ\����linux��Ϊ/��
   int length = strlen(src);
   printf("file length :%d\n", length);
   char dest_short_file_name[100];//ʹ������
   int i = 0;
   int last_split_occor_index = -1;
   for(i; i < length; i++){
        if(src[i] == split){
            last_split_occor_index = i;
        }
   }
    printf("last_split_occor_index :%d\n", last_split_occor_index);
   if(last_split_occor_index != -1){

        strncpy(dest_short_file_name, src+last_split_occor_index + 1, length - last_split_occor_index);
   }
    return dest_short_file_name;

}

main()
{
   //__FILE__��������ǰ�ļ�����һ���ַ�������������ļ����Ǿ���·����ֻ���������ļ���
   char *file_path = __FILE__;
//   char dest_short_file_name[100];//ʹ������
//   char * dest_short_file_name = (char *) malloc(100);//ʹ��ָ����Ҫ�Լ�����ռ�
   char * dest_short_file_name = (char *)get_short_file_name2(file_path);

   printf("dest_short_file_name :%s\n", dest_short_file_name);

   printf("FILE :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );

   free(dest_short_file_name);//�Լ��ͷſռ�

}
