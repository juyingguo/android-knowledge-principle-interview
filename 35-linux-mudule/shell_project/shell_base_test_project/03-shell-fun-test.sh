#!/bin/sh
#!/bin/bash
function demoFun1(){
    echo "这是我的第一个 shell 函数!"
    return `expr 1 + 1`
}

demoFun1
echo $?

function demoFun2(){
 echo "这是我的第二个 shell 函数!"
 expr 1 + 1
}

demoFun2
echo $?
demoFun1
echo 在这里插入命令！
echo $?
