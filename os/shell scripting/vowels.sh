#!/bin/bash


#To count the number of vowels in a text file

c=0
while read -n 1 char
do
    if [[ $char = a || $char = e || $char = i || $char = o || $char = u ]]
    then
        c=`expr $c + 1`
    fi
done < ./practice/shell/additional/vowel.txt

echo "Total number of vowels in file = $c"