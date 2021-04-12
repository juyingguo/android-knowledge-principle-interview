/**
题目：简单的结构体应用实例。

*/
//  Created by www.runoob.com on 15/11/9.
//  Copyright ? 2015年 菜鸟教程. All rights reserved.
//

#include <stdio.h>

struct programming
{
    float constant;
    char *pointer;
};

int main()
{
    struct programming variable;
    char string[] = "菜鸟教程：http://www.runoob.com";
    
    variable.constant = 1.23;
    variable.pointer = string;
    
    printf("%f\n", variable.constant);
    printf("%s\n", variable.pointer);
    
    return 0;
}
