#!/usr/bin/bash

echo "Enter decimal number"
read decimal

binary=""

while [ $decimal -gt 0 ]; do
    remainder=$((decimal%2))
    binary="$remainder"$binary
    decimal=$((decimal/2))
done

echo $binary