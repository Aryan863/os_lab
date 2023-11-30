#!/bin/bash

fact()
{
    n=$1
    sum=1
    # while [ $n -gt 0 ]
    # do
    #     sum=`expr $sum \* $n`
    #     n=`expr $n - 1`
    # done

    for (( i=1; i<=n; i++ ))
    do
        sum=`expr $sum \* $i`
    done

    echo "factorial= $sum"
}



echo "Enter number"
read num
fact $num

rec_fact $num
echo "rec fact= $?"