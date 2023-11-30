#!/bin/bash

max()
{
    n=$1
    maxi=`expr $n % 10`
    while [ $n -gt 0 ]
    do
        rem=`expr $n % 10`
        if [ $rem -gt $maxi ]
        then
            maxi=$rem
        fi
        n=`expr $n / 10`
    done

    return $maxi
}

min()
{
    n=$1
    mini=`expr $n % 10`
    while [ $n -gt 0 ]
    do
        rem=`expr $n % 10`
        if [ $rem -lt $mini ]
        then
            mini=$rem
        fi
        n=`expr $n / 10`
    done

    return $mini
}

avg()
{
    n=$1
    sum=0
    cnt=0
    while [ $n -gt 0 ]
    do
        rem=`expr $n % 10`
        sum=`expr $sum + $rem`
        n=`expr $n / 10`
        cnt=`expr $cnt + 1`
    done
    average=`echo "$sum / $cnt" |bc -l`

    echo "average of $num = $average"
}

echo "Enter number- "
read num
echo "Enter Operation-\n1.Max\n2.Min\n3.Average- "
read ch

case $ch in
1) max $num
   echo "max of $num = $?" ;;
2) min $num
   echo "min of $num = $?" ;;
3) avg $num ;;
*) echo "wrong choice"
esac