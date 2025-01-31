#!/bin/bash

# Script to find system information
while true; do
  echo "Select an option:"
  echo "1. Home directory"
  echo "2. Bash version"
  echo "3. Host name"
  echo "4. Current directory"
  echo "5. Exit"
  read choice

  case $choice in
    1) echo "Home directory: $HOME" ;;
    2) echo "Bash version: $BASH_VERSION" ;;
    3) echo "Host name: $(hostname)" ;;
    4) echo "Current directory: $(pwd)" ;;
    5) echo "Exiting..."; break ;;
    *) echo "Invalid choice. Please try again." ;;
  esac
done
