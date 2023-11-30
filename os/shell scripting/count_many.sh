#!/bin/bash

echo "No . line = $(wc -l ./practice/shell/additional/vowel.txt)"
echo "No . characters = $(wc -c ./practice/shell/additional/vowel.txt)"
b=0
s=0
v=0
while read -n 1 char 
do
    if [[ -z $char ]]
    then
    b=`expr $b + 1`
    fi
    if [[ "$char" =~ [!@#\&$%^*?] ]]
    then
    s=`expr $s + 1`
    fi
    if [[ $char =~ [AEIOUaeiou] ]]
    then
        v=`expr $v + 1`
    fi
done < ./practice/shell/additional/vowel.txt

echo "Blank spaces= $b"
echo "special characters= $s"
echo "vowels= $v"