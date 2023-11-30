#!/bin/bash

str=$(ls -l /)
# / DIR
# IFS=$'\n'
# for i in $str
# do
#     if [[ ${i:0:1} = "-" || ${i:0:1} = "d" || ${i:0:1} = "l" ]]
#     then
#         if [[ ${i:0:1} = "d" ]]
#         then
#             echo "DIR"
#             echo "${i:11:35}/${i:46}"
#         else
#             echo "${i:11}"
#         fi
#     fi
    
# done


# @ symbolic link
IFS=$'\n'
for i in $str
do
    if [[ ${i:0:1} = "-" || ${i:0:1} = "d" || ${i:0:1} = "l" ]]
    then
        if [[ ${i:0:1} = "l" ]]
        then
            echo "LINK"
            echo "${i:11:35}@${i:46}"
        else
            echo "${i:11}"
        fi
    fi
    
done