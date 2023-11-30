#!/bin/bash

str=$(ls ./practice/shell/additional)
mkdir ./practice/shell/additional/DISC

for i in $str
do
    c=${i:0:1}
    if [[ $c = d ]]
    then
        mv ./practice/shell/additional/$i ./practice/shell/additional/DISC
    fi
done