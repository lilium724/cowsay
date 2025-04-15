#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "showcow.h"

/*Variables correspondant au nombre de frame de l'animation voulue et 
à la résolution du rendu*/
#define NB_FRAMES 7
#define LINE_PER_FRAMES 6

/*frames de l'animation d'une vache qui se noie*/
char *noyade[NB_FRAMES][LINE_PER_FRAMES] = {{
"           (__) ",
"           (oo)",
"    /-------\\/",
"   / |     ||",
"  *  ||----||",
"     ~~    ~~"
},{
"           (__) ",
"           (oo)",
"    /-------\\/",
"   / |     ||",
"  *  ||----||",
"ccccccccccccccccc"
},{
"           (__) ",
"           (oo)",
"    /-------\\/",
"   / |     ||",
"ccccccccccccccccc",
" "
},{
"           (__) ",
"           (oo)",
"    /-------\\/",
"ccccccccccccccccc",
"",
" "
},{
"           (__) ",
"           (oo)",
"ccccccccccccccccc",
" ",
" ",
" "
},{
"           (__) ",
"ccccccccccccccccc",
" ",
" ",
" ",
" "
},{ 
"ccccccccccccccccc",
" ",
" ",
" ",
" ",
" "
}};

/*affiche une frame en positionnant le 
coin haut gauche de l'image aux coordonée x et y entrée en paramètre*/
void position(char **vache, int x, int y){
    for (int i = 0; i<LINE_PER_FRAMES; i++){
        gotoxy(x+i+1,y);
        printf("%s", vache[i]);
        printf("\n");
    }
}

int main (){
    update();
    for (int i = 0; i<NB_FRAMES; i++){
        position(noyade[i], 3, 10);
        usleep(500000);
        update();
    }
    return 0;
}