#!/bin/bash

if [ ! $# -eq 2 ]
then
    echo "Must specify writefile and writestr on the command line"
    exit 1
fi

direc=$(dirname $1)
mkdir -p $direc
echo $2 > $1

retval=$(ls $1 | wc -l)


if [ ! $retval -eq 1 ]
then
    echo "Unable to create a file"
    exit 1
fi
