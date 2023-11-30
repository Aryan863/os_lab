#!/bin/bash

c=0
while read -n 1 char
do
    if [[ $char = "!" || $char = "@" || $char = "#" || $char = "$" || $char = "%" || $char = "^" || $char = "&" || $char = "*" || $char = "?" ]]
    then
        c=`expr $c + 1`
    fi
done < ./practice/shell/additional/vowel.txt

echo "Total special characters= $c"