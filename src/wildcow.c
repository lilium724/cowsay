#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/*Teste push*/

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