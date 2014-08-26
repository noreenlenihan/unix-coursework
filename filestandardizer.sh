#! /bin/bash

mkdir dir

cd dir
touch file1 File1 FILE2 FiLe3
cd ..

for filename in dir/*; do
    if [[ $filename == *[[:upper:]]* ]]; then
        filelower=$(echo $filename | tr "A-Z" "a-z")
        if [ -f "$filelower" ]; then
            echo "file $(basename "$filelower") already exists"
        else mv "$filename" "$filelower"
        fi
    fi
done