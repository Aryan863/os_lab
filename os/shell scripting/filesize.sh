#!/bin/bash

str=$(ls -l)
str=echo ls -l | cut -d' ' -f5

# echo "$str" | head -n 1
max=-1
IFS=$'\n'
for i in $str
do
    size=${i:25:8}
    #echo "$i"
done