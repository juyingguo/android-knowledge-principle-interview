#include<stdio.h>
#include<stdlib.h>

void  tentotwo(int num,int baseFlag)
{


    if(2 != baseFlag && 8 != baseFlag && baseFlag != 10){

        printf("baseFlag should 2,or 8,10.");
        return;

    }



	if (num!=0)
	{
		int m = num % baseFlag;//ȡ����
		num = num / baseFlag;
		      //˳��
		tentotwo(num,baseFlag);
		printf("%d", m);//����



	}
   else
   {
		printf("\n");

    }



}


void main()
{
	tentotwo(10,2);//1010

    tentotwo(10,8);
	system("pause \n");






}
