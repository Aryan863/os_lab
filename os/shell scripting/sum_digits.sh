#!/bin/bash

n=$1
sum=0
while [ $n -gt 0 ]
do
    rem=`expr $n % 10`
    sum=`expr $rem + $sum`
    n=`expr $n / 10`
done

echo "Sum of digits= $sum"