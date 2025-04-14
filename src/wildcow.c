#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NB_FRAMES 7
#define LINE_PER_FRAMES 6
void update () { 
    printf ( "\033[H\033[J" ); 
}

void gotoxy ( int x , int y ) { 
    printf ( "\033[%d;%dH" ,x , y ); 
}

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
}#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void update () { 
    printf ( "\033[H\033[J" ); 
}

void gotoxy ( int x , int y ) { 
    printf ( "\033[%d;%dH" ,x , y ); 
}

int main (){
    gotoxy(100, 100);
    printf("%s\n%s\n", "hello", "world");
    return 0;
}