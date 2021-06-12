#!/bin/sh
my_array=(A B "C" D)

echo "数组的元素为: ${my_array[*]}"
echo "数组的元素为: ${my_array[@]}"

for element in ${my_array[@]}
	do
 echo "element is ${element}"
done