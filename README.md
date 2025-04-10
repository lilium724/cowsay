# Cowsay

Cowsay est une application pour bash qui prend un texte et l'affiche dans une
bulle au dessus d'un ascii d'une vache.

NAME
    newcow - configurable speaking/thinking cow (and a bit more)

SYNOPSIS
    newcow [Options]  [<message>]

    newcow -s bonjour

DESCRIPTION
       cowsay generates an ASCII-art picture of a cow saying something provided by the user. If run with no non-option arguments, it reads from standard input,
       word-wraps the given message at about 40 columns, and prints the cow saying the given message on standard output.

       If any command-line arguments are left over after all switches have been processed, they become the cow’s message, instead of using standard input. Standard input
       is ignored in this case.

OPTIONS
       There are several provided modes which change the appearance of the cow depending on its particular emotional/physical state.

   Cow modification

      -e
           Selects the appearance of the cow’s eyes, in which case the first two characters of the argument string eye_string will be used. The default eyes are 00.

       -s
           Makes the cow appear thoroughly stoned.

       -t 
           Select the lenth of the cow's legs

       -q
           Select the lenth of the cow's tail
