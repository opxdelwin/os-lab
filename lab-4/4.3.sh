#1/usr/bin/bash

echo "enter hgrade on 100: "
read grade

if [ $grade -ge 90 ]; then
    echo "Outstanding"
elif [ $grade -ge 80 ]; then
    echo "Great"
elif [ $grade -ge 70 ]; then
    echo "A"
elif [ $grade -ge 60 ]; then
    echo "B"
elif [ $grade -ge 50 ]; then
    echo "C"
elif [ $grade -ge 40 ]; then
    echo "D"
else
    echo "F"
fi