#!/usr/bin/bash

echo "Enter year: "
read x

if (( x % 400 == 0 )); then
    echo "It's a leap year"
elif (( x % 100 == 0 )); then
    echo "Not a leap year"
elif (( x % 4 == 0 )); then
    echo "It's a leap year"
else
    echo "Not a leap year"
fi
