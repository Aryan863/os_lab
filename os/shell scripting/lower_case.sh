#!/bin/bash

str=$(tr [A-Z] [a-z] < ./practice/shell/additional/vowel.txt) 
echo "$str" | cat > ./practice/shell/additional/vowel.txt