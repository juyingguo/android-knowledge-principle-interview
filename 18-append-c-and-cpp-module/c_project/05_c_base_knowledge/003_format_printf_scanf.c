/**
��Ŀ���򵥵Ľṹ��Ӧ��ʵ����

*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015�� ����̳�. All rights reserved.
//

#include <stdio.h>
#include <string.h> 

int main()
{
    
    char string[] = "abc\0\0";
    char string_b[] = "����china";
    printf("%d\n", strlen(string));
    printf("%d\n", strlen(string_b));
    printf("**********\n");     
    printf("%d\n", 0%2); 
	printf("%d\n", 1%2); 
    printf("%d\n", 2%2); 
    printf("%d\n", 3%2); 
    printf("********3d**\n");   
    printf("%3d\n", 5); 
    printf("%03d\n", 5); 
    printf("%3d\n", -5); 
    printf("%-3d\n", 5); 
    printf("%+3d\n", 5);  
    printf("%+03d\n", 5); 
    printf("%0+3d\n", 5); 
    printf("*******3f**\n");   
    printf("%3f\n", 5.2); 	    
    printf("%-3f\n", 5.2); 
    printf("%+3f\n", 5.2); 
    printf("%.3f\n", 5.2); 
    printf("%-3.3f\n", 5.2); 
    printf("%+3.3f\n", 5.2); 
    return 0;         
}
