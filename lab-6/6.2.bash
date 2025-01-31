#!/bin/bash

delete_at_index() {
    local index=$1
    shift
    local array=("$@")
    unset array[$index]
    echo "${array[@]}"
}

echo "Enter the elements of the array (space-separated):"
read -a array

echo "Enter the index to delete:"
read index

if [ $index -ge 0 ] && [ $index -lt ${#array[@]} ]; then
    new_array=$(delete_at_index $index "${array[@]}")
    echo "New array: $new_array"
else
    echo "Invalid index"
fi