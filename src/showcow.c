#include <stdio.h>
#include <string.h>

void bulle (char *text){
	char top[100]="";
	char bot[100]="";
	/*passe sur chaque caractère de la liste et rajoute les contours*/
	for (int i = 0; text[i]; i++){
		strcat(top, "_");
		strcat(bot,"-");
	}
	/*affiche le texte avec le bon format*/
	printf(" %s\n<%s>\n %s\n", top, text, bot);
}

void affiche_vache(char *eyes, char *tongue, int legs, char *queue) {
	printf("\
   \\	^__^\n\
    \\	(%s)\\_______\n\
        (__)\\	    )\\/\\%s \n\
	 %s||----w |\n\
           ||     ||\n", eyes, queue, tongue);

  for(int i = 0; i < legs; i++) {
    printf("           ||     ||\n");
  }

}

void update() {
  printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
  printf("\033[%d;%dH", x, y);
}
