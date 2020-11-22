#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**

预定义宏
    ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。

    宏	描述
    __DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
    __TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
    __FILE__	这会包含当前文件名，一个字符串常量。
    __LINE__	这会包含当前行号，一个十进制常量。
    __STDC__	当编译器以 ANSI 标准编译时，则定义为 1。


    https://www.runoob.com/cprogramming/c-preprocessors.html
*/
/**
从给的完整路径文件名中获取简短的文件名称
*/
void get_short_file_name(char *desc,char *src){

    char split = '\\';//路径\需要转义。路径在window下为\，在linux下为/。
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

    char split = '\\';//路径\需要转义。路径在window下为\，在linux下为/。
   int length = strlen(src);
   printf("file length :%d\n", length);
   char * dest_short_file_name = (char *) malloc(100);//使用指针需要自己分配空间
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
//    free(dest_short_file_name);//此时释放空间，导致调用者获取不到内容
    return dest_short_file_name;

}
/**
从给的完整路径文件名中获取简短的文件名称
全局数组在程序运行结束时自动释放。

函数内定义的数组在函数退出时自动释放。
获取的内容为空。
*/
void * get_short_file_name3(/*char *desc,*/char *src){

    char split = '\\';//路径\需要转义。路径在window下为\，在linux下为/。
   int length = strlen(src);
   printf("file length :%d\n", length);
   char dest_short_file_name[100];//使用数组
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
   //__FILE__这会包含当前文件名，一个字符串常量。如果文件名是绝对路径，只保留最后的文件名
   char *file_path = __FILE__;
//   char dest_short_file_name[100];//使用数组
//   char * dest_short_file_name = (char *) malloc(100);//使用指针需要自己分配空间
   char * dest_short_file_name = (char *)get_short_file_name2(file_path);

   printf("dest_short_file_name :%s\n", dest_short_file_name);

   printf("FILE :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );

   free(dest_short_file_name);//自己释放空间

}
