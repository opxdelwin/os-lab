#!/bin/bash

echo "Enter the elements of the array:"
read -a array

length=${#array[@]}

echo "Array in reverse order:"
for (( i=$length-1; i>=0; i-- ))
do
    echo "${array[$i]} "
done
echo