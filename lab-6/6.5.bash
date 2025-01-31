#!/bin/bash

linear_search() {
    local arr=("$@")
    local key=${arr[-1]}
    unset arr[-1]
    
    for i in "${!arr[@]}"; do
        if [[ "${arr[$i]}" == "$key" ]]; then
            echo "Element found at index: $i"
            return 0
        fi
    done
    
    echo "Element not found"
    return 1
}

read -p "Enter the elements of the array: " -a array
read -p "Enter the element to search: " key

array+=("$key")

linear_search "${array[@]}"