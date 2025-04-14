#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void update () { 
    printf ( "\033[H\033[J" ); 
}

void gotoxy ( int x , int y ) { 
    printf ( "\033[%d;%dH" ,x , y ); 
}

char *noyade[] = {
"   (__) \n\
        (oo)\n\
 /-------\\/\n\
/ |     ||\n\
*  ||----||\n\
  ~~    ~~"
};

void affiche_vache(char **anim, int x, int y){
    for (int i = 0; &anim[i]; i++){
        gotoxy(x,y);
        for (int j = 0; &anim[i][j]; j++){
            printf("%c", anim[i][j]);
        }
    }
}

int main (){
    for (int i = 0; i<10 ; i++){
        gotoxy(i,i*2);
        affiche_vache(noyade, 100, 100);
        usleep(100000);
        update();
    }
    return 0;
}