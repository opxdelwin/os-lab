#!/bin/bash
numbers=(1 2 3 4 5 6 7 8 9 10)

echo "All numbers:"
for n in "${numbers[@]}"; do
    echo "$n"
done

echo "Skipping 5 using continue:"
for n in "${numbers[@]}"; do
    if [ "$n" -eq 5 ]; then
        continue
    fi
    echo "$n"
done

echo "Stopping at 5 using break:"
for n in "${numbers[@]}"; do
    if [ "$n" -gt 5 ]; then
        break
    fi
    echo "$n"
done