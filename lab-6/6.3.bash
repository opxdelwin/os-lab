#!/bin/bash

echo "Enter the elements of the array separated by space:"
read -a array

unique_elements=()

for element in "${array[@]}"; do
    if [[ ! " ${unique_elements[@]} " =~ " ${element} " ]]; then
        unique_elements+=("$element")
    fi
done

echo "Array after removing duplicates:"
for element in "${unique_elements[@]}"; do
    echo -n "$element "
done
echo