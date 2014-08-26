#! /bin/bash

if [ ! $# -eq 1 ];then 
    echo "Incorrect number of args. Usage: ./scriptq1.sh <some argument>" 1>&2
    exit 1
fi

if [ ! -f $1 ];then 
    echo "$1 is not a file, man!" 1>&2
    exit 1
fi

wordcount=0
for word in $(cat $1); do
    let wordcount=$(($wordcount + 1));
done

echo $wordcount