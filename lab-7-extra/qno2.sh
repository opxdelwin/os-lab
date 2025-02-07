#!/bin/bash

#2. Write a shell script to enter a file name. If it exists, append some content into it. If it doesn't exist, create the file and add content.

# Prompt user to enter a file name
echo "Enter the file name:"
read filename

# Check if the file exists
if [ -e "$filename" ]; then
    # File exists, append content
    echo "File '$filename' exists. Appending content."

    # Prompt user to enter content to append
    echo "Enter content to append (press Ctrl+D when finished):"
    while IFS= read -r line
    do
        echo "$line" >> "$filename"
    done

    echo "Content appended to '$filename'."

else
    # File does not exist, create file and add content
    echo "File '$filename' does not exist. Creating file and adding content."

    # Prompt user to enter content to add
    echo "Enter content to add (press Ctrl+D when finished):"
    while IFS= read -r line
    do
        echo "$line" >> "$filename"
    done

    echo "Content added to '$filename'."
fi

