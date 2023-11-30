#!/bin/bash

echo "Enter file name"
read fname

if [ -z $fname ]
then
    echo "File name not entered"
    exit 1
fi

# Check if the file exists
if [ ! -e $fname ]
then
    echo "File not found"
    exit 1
fi

# Determine file type
if [ -f $fname ]
then
    file_type="Regular File"
elif [ -d $fname ]
then
    file_type="Directory"
elif [ -c $fname ]
then
    file_type="Character device"
elif [ -b $fname ]
then
    file_type="block device"
elif [ -l $fname ]
then
    file_type="link type"
else
    file_type="unknown"
fi

#Determine file permissions
if [ -r $fname ]
then
    echo "Read present"
else
    echo "Read not present"
fi

if [ -w $fname ]
then
    echo "write present"
else
    echo "write not present"
fi

if [ -x $fname ]
then
    echo "execute present"
else
    echo "execute not present"
fi


# Check file permissions
permissions=$(ls -l $fname | cut -c 1-10)
echo $permissions
owner_permissions=${permissions:1:3}
group_permissions=${permissions:4:3}
others_permissions=${permissions:7:3}

echo "File Type: $file_type"
echo "Owner Permissions: $owner_permissions"
echo "Group Permissions: $group_permissions"
echo "Others Permissions: $others_permissions"