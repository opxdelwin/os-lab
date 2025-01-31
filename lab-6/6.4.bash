#!/bin/bash

insert_at_index() {
    local array=("${!1}")
    local index=$2
    local element=$3
    local new_array=()

    for ((i=0; i<${#array[@]}; i++)); do
        if [ $i -eq $index ]; then
            new_array+=("$element")
        fi
        new_array+=("${array[$i]}")
    done

    if [ $index -ge ${#array[@]} ]; then
        new_array+=("$element")
    fi

    echo "${new_array[@]}"
}

read -p "Enter the elements of the array: " -a user_array

read -p "Enter the index at which to insert the new element: " index
read -p "Enter the element to insert: " element

result_array=($(insert_at_index user_array[@] $index $element))

echo "Array after insertion: ${result_array[@]}"