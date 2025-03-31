#!/bin/bash
for i in $(seq 1 $1) ; do
	clear
	cowsay $i
	sleep 1
done
