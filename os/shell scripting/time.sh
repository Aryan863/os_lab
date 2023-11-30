#!/bin/bash

# shell program to print GM ,GN based on current time

str=$(date)
time=${str:11:2}
echo "current time= $time"



if [[ $time -gt 4 && $time -lt 12 ]]
then
    echo "Good morning!!"
elif [[ $time -ge 12 && $time -lt 17 ]]
then
    echo "Good Afternoon"
elif [[ $time -ge 17 && $time -lt 20 ]]
then
    echo "Good evening"
else
    echo "Good night"
fi