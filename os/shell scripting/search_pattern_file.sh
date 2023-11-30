#!/bin/bash

echo "Enter Pattern"
read pat
echo "Enter filename"
read fname

if [ -z $pat ]
then
    echo "Pattern not entered"
    exit 1
fi

if [ ! -n $fname ]
then
    echo "Filename not entered"
    exit 2
fi

grep $pat $fname
if [ $? -eq 0 ]
then
    echo "Pattern found"
else
    echo "Pattern not found"
fi