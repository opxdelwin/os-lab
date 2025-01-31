#!/bin/bash

# Script to check if a given string is a palindrome
echo "Enter a string: "
read str
reverse=$(echo "$str" | rev)

if [ "$str" == "$reverse" ]; then
  echo "The string is a palindrome."
else
  echo "The string is not a palindrome."
fi
