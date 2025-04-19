#include <stdio.h>
#include <string.h>
#include "showcow.h"

/*met le texte affichée dans une bulle*/
void bulle (Parameters *param){
	char top[100]="";
	char bot[100]="";
	/*passe sur chaque caractère de la liste et rajoute les contours*/
	for (int i = 0; param->text[i]; i++){
		strcat(top, "_");
		strcat(bot,"-");
	}
	/*affiche le texte avec le bon format*/
	printf(" %s\n<%s>\n %s\n", top, param->text, bot);
}

/*permet d'afficher la vache*/
void affiche_vache(Parameters *param) {
  printf("\
   \\	^__^\n\
    \\	(%s)\\_______\n\
        (__)\\	    )\\/\\", param->eyes);

  for(int i = 0; i < param->tail; i++) {
    if(i%2)
      printf("\\");
    else
      printf("/");
  }
  puts("");
  printf("\
	 %s||----w |\n\
           ||     ||\n", param->tongue);

  for(int i = 0; i < param->legs; i++) {
    printf("           ||     ||\n");
  }

}


void update() {
  printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", x, y);
}
