#!/bin/bash

echo "Enter a number for factorial: "
read n

prod=1
for ((i=1; i<=n; i++)); do
    prod=$((prod * i))
done

echo "Factorial of $n is $prod"
