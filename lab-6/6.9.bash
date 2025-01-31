#!/usr/bin/bash

echo "Enter A: "
read A
echo "Enter B: "
read B

swap(){
    local temp=$A
    A=$B
    B=$temp
}

swap "A" "B"
echo $A
echo $B
