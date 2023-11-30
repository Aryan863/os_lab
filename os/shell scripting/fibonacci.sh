#!/bin/bash

a=0
b=1
n=10
echo "$a"
echo "$b"
for (( i=3; i<=n; i++ ))
do
    c=`expr $a + $b`
    echo "$c"
    a=$b
    b=$c
done
