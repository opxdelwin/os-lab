#!/bin/bash

# Script to check if a given integer is a palindrome
echo "Enter an integer: "
read num

original_num=$num
reverse=0

while [ $num -gt 0 ]; do
    remainder=$((num % 10))
    reverse=$((reverse * 10 + remainder))
    num=$((num / 10))
done

if [ $original_num -eq $reverse ]; then
  echo "The integer is a palindrome."
else
  echo "The integer is not a palindrome."
fi
