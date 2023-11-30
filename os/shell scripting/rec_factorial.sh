#!/bin/bash

rec_fact()
{
    if [ $1 -le 1 ]
    then
        return 1
    else
        a=`expr $1 - 1`
        echo "a= $a"
        rec_fact $a
        b=`expr $1 \* $?`
        echo "b= $b"
        return $b
    fi
}

echo "Enter number"
read num

rec_fact $num
echo "rec fact= $?"