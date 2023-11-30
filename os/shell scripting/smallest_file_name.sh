#!/bin/bash

str=$(ls ./practice/shell/additional)
min=99
fname=""
for i in $str
do
    c=${#i}                 # any string operation involves {}
    if [[ $c -lt $min ]]
    then
        min=$c
        fname=$i
    fi
done

echo "Smallest file name= $fname"