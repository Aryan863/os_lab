#!/bin/bash

str=$(cat ./practice/shell/additional/vowel.txt)

IFS=$'\n'
c=1
for i in $str
do
    if [[ `expr $c % 2` -eq 0 ]]
    then
        echo "$i" | cat >> ./practice/shell/additional/output.txt
    fi
    c=`expr $c + 1`
done