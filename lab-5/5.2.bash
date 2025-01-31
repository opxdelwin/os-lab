#!/bin/bash
#declare a static array
arr=("Jayesh" "Shivang" "1" "Vipul" "Nishant" "2")

#To print all elements of an array
echo "${arr[@]}"
echo "${arr[*]}"

#To print 1st element
echo "${arr[0]}"

#To print from a custom start point
echo "${arr[@]:2}"
echo "${arr[*]:2}"

#To print from a range
echo "${arr[@]:1:3}"
echo "${arr[@]:1:3}"

#To print length of array
echo "${#arr[*]}"

#To search from an array
search_result=$(echo "${arr[@]}" | grep -c "Jayesh")
echo "Jayesh is at: $search_result"

#To replace in an array
replaced_element=$(echo "${arr[@]/Shivang/SHIVANG}")
echo "Mewo: $replaced_element"

#To delete from an array
unset arr[3]
echo "${arr[*]}"
