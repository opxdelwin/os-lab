#!/bin/bash

#3. Write a menu-driven file-handling shell program. Let it offer the user the choice of creating, copying, removing and renaming files. Once the user has made a choice, have the program ask the user for the necessary information and execute the corresponding code.

# Function to create a new file
create_file() {
    echo "Enter the name of the file to create:"
    read filename
    touch "$filename"
    echo "File '$filename' created."
}

# Function to copy a file
copy_file() {
    echo "Enter the name of the source file:"
    read source_file
    echo "Enter the name of the destination file:"
    read destination_file
    cp "$source_file" "$destination_file"
    echo "File '$source_file' copied to '$destination_file'."
}

# Function to remove a file
remove_file() {
    echo "Enter the name of the file to remove:"
    read filename
    rm -i "$filename"
    echo "File '$filename' removed."
}

# Function to rename a file
rename_file() {
    echo "Enter the current name of the file:"
    read old_filename
    echo "Enter the new name of the file:"
    read new_filename
    mv "$old_filename" "$new_filename"
    echo "File '$old_filename' renamed to '$new_filename'."
}

# Menu
echo "Menu:"
    echo "1. Create a new file"
    echo "2. Copy a file"
    echo "3. Remove a file"
    echo "4. Rename a file"
    echo "5. Exit"
while true
do
    echo "Enter your choice:"
    read choice
    case $choice in
        1) create_file ;;
        2) copy_file ;;
        3) remove_file ;;
        4) rename_file ;;
        5) echo "Exiting program."
           break ;;
        *) echo "Invalid choice. Please enter a number from 1 to 5."
    esac
done

