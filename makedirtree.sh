#!/bin/bash

if [ $# -ne 1 -o ! -d $1 ]; then
    echo "Incorrect no. of args. Usage ./script4.sh <some directory>"
fi

echo $1

listsubs()
{

cd $2

local subdir_items=0
local overall_items=$( ls | wc -l)

for items in $(ls); do
    subdir_items=$(($subdir_items + 1))
    echo "$1|-- $items"
    if [ -d $items ]; then
        if [[ $subdir_items -eq $overall_items ]]; then
                listsubs "$1  " $items
        else
                listsubs "$1| " $items
        fi
    fi
done
cd ..

}

listsubs "" $1

