#!/usr/bin/bash

echo "Enter a number: "
read x
original=$x
temp=$x

while [ $temp -gt 0 ]; do
    lastNum=$((temp%10))
    temp=$((temp/10))
    rev=$(( (rev*10) +lastNum ))
done

if [ $original -eq $rev ]; then
    echo "$original is a palindrome"
else
    echo "$original is not a palindrome"
fi