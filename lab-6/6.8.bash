#!/bin/bash

selection_sort() {
    arr=("$@")
    n=${#arr[@]}
    
    for ((i = 0; i < n-1; i++)); do
        min_index=$i
        for ((j = i+1; j < n; j++)); do
            if (( arr[j] < arr[min_index] )); then
                min_index=$j
            fi
        done
        temp=${arr[i]}
        arr[i]=${arr[min_index]}
        arr[min_index]=$temp
    done

    echo "${arr[@]}"
}

read -p "Enter the elements of the array:" -a array

sorted_array=($(selection_sort "${array[@]}"))

echo "Sorted array: ${sorted_array[@]}"