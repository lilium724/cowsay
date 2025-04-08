#!/bin/bash
#convertion d'un nombre decimal en binaire
dec=$1
bin=0
oc=1
while [ $dec -ne 0 ]
do
bin=$(($(($(($dec%2))*$oc))+$bin))
dec=$(($dec/2))
oc=$(($oc*10))
done
cowsay $bin

