#!/bin/bash
# String Palindrome Program in Bash Shell

echo "Enter a String"
read input
reverse=""

len=${#input}
for (( i=$len-1; i>=0; i-- ))
do 
	reverse+="${input:$i:1}"
done

if [ $input = $reverse ]
then
    echo "$input is palindrome"
else
    echo "$input is not palindrome"
fi

