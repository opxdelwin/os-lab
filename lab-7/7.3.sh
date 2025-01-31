#!/usr/bin/bash

read -p "Enter a long number: " -a number
sum=0
digits=0
while [[ $number -gt 0 ]]; do
    digit=$((number % 10))
    sum=$((sum + digit))
    number=$((number / 10))
    digits=$((digits + 1))
done

echo "Sum :$sum"
echo "Avg: $((sum / digits))"