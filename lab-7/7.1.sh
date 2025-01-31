#!/usr/bin/bash

read -p "Enter base number: " a
read -p "Enter exponent: " b
result=$a
for ((i=1; i<$b; i++)); do
    result=$((result*a))
done
echo "Ep: $result"
