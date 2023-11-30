#!/bin/bash

echo "Enter a number"
read n

c=0
for (( i=1; i<=n ; i++ ))
do
    if [[ `expr $n % $i` == 0 ]]
    then
        c=`expr $c + 1`
    fi
done

if [ $c -eq 2 ]
then
    echo "It is prime number"
else
    echo "Not a prime number"
fi