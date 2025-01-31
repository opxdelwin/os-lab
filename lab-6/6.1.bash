#!/bin/bash

bubble_sort() {
    local array=("$@")
    local n=${#array[@]}
    for ((i = 0; i < n-1; i++)); do
        for ((j = 0; j < n-i-1; j++)); do
            if ((array[j] > array[j+1])); then
                temp=${array[j]}
                array[j]=${array[j+1]}
                array[j+1]=$temp
            fi
        done
    done
    echo "Sorted array: ${array[@]}"
}

read -p "Enter the elements of the array: " -a user_array

bubble_sort "${user_array[@]}"