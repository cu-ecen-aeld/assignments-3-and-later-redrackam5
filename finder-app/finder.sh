#!/bin/bash

if [ ! $# -eq 2 ]
then
    echo "Must specify filesdir and searchstr on the command line"
    exit 1
fi

if [ ! -d $1 ]
then
    echo "The first argument to the script must be a directory"
    exit 1
fi

numfiles=$(find $1 -type f -follow -print | wc -l)
matchlines=$(find $1 -type f -follow | xargs grep $2 | wc -l)


echo The number of files are $numfiles and the number of matching lines are $matchlines
