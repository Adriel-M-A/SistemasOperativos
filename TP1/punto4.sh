#! /bin/bash

clear

if [ -f $1 ]
then
    if [ $2 == "-A" ]
    then
        sort $1
    elif [ $2 == "-Z" ]
    then
        sort -r $1
    else
        echo "$./nombre_script.sh [archivo]  [-A|-Z]"
    fi
else
    echo "$./nombre_script.sh [archivo]  [-A|-Z]"
fi