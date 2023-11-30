#!/bin/bash

echo "Enter your name"
read name

for i in $name
do
    initial=${i:0:1}
    echo -n "$initial "
done