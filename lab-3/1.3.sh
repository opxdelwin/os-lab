#!/usr/bin/bash

echo "Enter distance in km: "
read x

echo "Distance in meter: $(($x*1000))"
echo "Distance in cm: $(($x*100000))"
