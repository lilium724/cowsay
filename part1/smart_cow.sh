#!/bin/bash

#cowsay $1 -T $(eval $1) -> tout est ecrit dans la bulle (-T inclus)

#cowsay -T $(eval $1) $1 -> eval n'est pas pour les opérations arithmétiques

#cowsay -T $(($1)) $1 -> presque, c'est -e pour les yeux

cowsay -e $(($1)) $1
