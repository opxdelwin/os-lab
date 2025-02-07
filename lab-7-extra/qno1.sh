#!/bin/bash

#1. Write a shell script to enter a file name and check if it exists. If yes, check and display its read, write and execute permissions.

# Prompt user to enter a file name
echo "Enter the file name:"
read filename

# Check if the file exists
if [ -e "$filename" ]; then
    echo "File '$filename' exists."

    # Check and display read permission
    if [ -r "$filename" ]; then
        echo "Read permission: Yes"
    else
        echo "Read permission: No"
    fi

    # Check and display write permission
    if [ -w "$filename" ]; then
        echo "Write permission: Yes"
    else
        echo "Write permission: No"
    fi

    # Check and display execute permission
    if [ -x "$filename" ]; then
        echo "Execute permission: Yes"
    else
        echo "Execute permission: No"
    fi

else
    echo "File '$filename' does not exist."
fi

echo "Hello World"
echo "hello world"
