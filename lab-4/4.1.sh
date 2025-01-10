#!/usr/bin/bash

echo "Enter a number (1-5): "
read x

case $x in
    1) echo "one";;
    2) echo "two";;
    3) echo "three";;
    4) echo "four";;
    5) echo "five";;
    *) echo "Invalid number";;
esac
