echo "Enter the marks: "
read marks

case $marks in
  9[0-9]|100) echo "Grade: O";;
  8[0-9]) echo "Grade: E";;
  7[0-9]) echo "Grade: A";;
  6[0-9]) echo "Grade: B";;
  5[0-9]) echo "Grade: C";;
  4[0-9]) echo "Grade: D";;
  *) echo "Grade: F";;
esac
