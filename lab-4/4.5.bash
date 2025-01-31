#!/bin/bash

# Script to perform operations on up to 8 integer arguments
if [ $# -lt 2 ]; then
  echo "Please provide at least 2 arguments (up to 8)."
  exit 1
fi

if [ $# -gt 8 ]; then
  echo "Too many arguments. Maximum allowed is 8."
  exit 1
fi

result=$1

shift
for b in "$@"; do
  if [ $((result % b)) -eq 0 ]; then
    result=$((result / b))
  elif [ $((b % 5)) -eq 0 ]; then
    result=$((result * b))
  elif [ $result -gt $b ]; then
    result=$((result - b))
  else
    result=$((result + b))
  fi
done

echo "Final result: $result"
