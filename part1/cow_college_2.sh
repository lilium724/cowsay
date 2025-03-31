#!/bin/bash
a=1
b=1
while [ $a -lt $1 ] ; do
	clear
	cowsay $a
	let next=$a+$b
	b=$a
	a=$next
	sleep 1
done

#problèmes rencontrés : des espaces entre les = (interdit)
#besoin d'ajouter une variable tampon (swap)
