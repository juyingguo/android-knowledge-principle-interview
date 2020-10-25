#!/bin/bash
# author:菜鸟教程
# url:www.runoob.com
echo "-- \$* 演示 ---"
for i in "$*"
do
    echo $i;
done;

echo "-- \$@ 演示 ---"
for i in "$@"; do
    echo $i
done
