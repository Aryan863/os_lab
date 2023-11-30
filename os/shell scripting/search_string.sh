#!/bin/bash

echo "Enter string"
read str
echo "Enter string to be searched"
read n

if [[ `echo "$str" | grep "$n"` ]]
then
    echo "String is present"
else
    echo "String is not present"
fi