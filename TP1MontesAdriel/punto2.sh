#! /bin/bash

#numero de parametros recibidos
cant_argumentos=$#

i=1

while [ $i -le $cant_argumentos ]
do
    echo $1
    shift
    i=$(( $i + 1 ))
done