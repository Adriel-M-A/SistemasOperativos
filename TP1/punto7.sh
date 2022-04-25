#! /bin/bash
#

if [ $# -lt 1 -o $# -gt 2 ]; then
    echo "cantidad incorrecta de parametros"
    exit 1
fi

if [ "$1" == "-" ]; then
    for i in *
    do
        grep "$2" $i #> /deb/null || echo $i
    done
else
    for i in *
    do
        grep "$1" $i #> /deb/null || echo $i
    done
fi