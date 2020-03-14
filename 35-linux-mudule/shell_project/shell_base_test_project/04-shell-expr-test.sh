#!/bin/sh


echo "Hello World !"

a=10
b=20

val=`expr $a + $b`
echo "a + b : $val"

val=`expr ${a} - ${b}` ##right 
echo "a - b : $val"


val= expr ${a} - ${b}	##only output -10,val has not right value.
echo "a - b : $val"

val= expr $a \* $b
echo "a * b : $val"

expr $a+$b ## error ,output : 10*20

expr $a + $b + 10



