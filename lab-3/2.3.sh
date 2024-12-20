#!/bin/bash

echo "Prime numbers between 1 and 100 are:"

# Loop through numbers from 2 to 100
for ((num=2; num<=100; num++))
do
    is_prime=1
    for ((i=2; i*i<=num; i++))
    do
        if ((num % i == 0)); then
            is_prime=0 # Not a prime number
            break
        fi
    done

    if ((is_prime == 1)); then
        echo "$num"
    fi
done

