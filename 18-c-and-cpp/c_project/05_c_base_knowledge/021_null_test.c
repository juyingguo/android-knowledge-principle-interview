#include <stdio.h>
#include <string.h>

struct Student
{
   char  title[50];
   int *p;

};
int main()
{

    struct Student stu;        /* 声明 stu，类型为 Student */

    struct Student *s2 = &stu;

    /* Student 详述 */
    strcpy( stu.title, "C Programming");
    stu.p = NULL;

    int *x = NULL;
    if(x == NULL){
        printf("(x == NULL)\n");
    }else {
        printf("(x != NULL)\n");

    }
    if(x){
         printf("x is true \n");
    }else{
         printf("x is false \n");

    }

//    printf("(*x) = %d\n",*x);

    int p  = 10;
    x = &p;

    printf("(*x) = %d\n",*x);

    if(x){
         printf("x is true \n");
    }
    stu.p = &p;
    if(x && stu.p){
         printf("x and stu.p are true\n");
    }

    printf("s2->title is %s \n",s2->title);

    if(s2->title){
        printf("s2->title is true \n");
    }
    return 0;
}

