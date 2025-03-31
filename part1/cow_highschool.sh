#!/bin/bash
for i in $(seq 1 $1) ; do
	clear
	cowsay $(($i*$i))
	sleep 1
done
