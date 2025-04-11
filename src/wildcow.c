#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "newcow.h"
void update () { 
    printf ( "\033[H\033[J" ); 
}

void gotoxy ( int x , int y ) { 
    printf ( "\033[%d;%dH" ,x , y ); 
}

int main (){
    for (int i = 0; i<10 ; i++){
        gotoxy(i,i*2);
        printf("hello\n");
        usleep(100000);
        update();
    }
    return 0;
}