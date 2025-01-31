#!/bin/bash

arr=()

echo "Enter elements of the array (type 'done' to finish):"
while true; do
    read element
    if [ "$element" == "done" ]; then
        break
    fi
    arr+=("$element")
done

echo "The elements of the array are:"
for i in "${arr[@]}"; do
    echo "$i"
done