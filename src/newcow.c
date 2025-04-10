#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


void affiche_vache(char *eyes,char *stoned, char *legs) {
	printf("\
   \\	^__^\n\
    \\	(%s)\\_______\n\
        (__)\\	    )\\/\\\n\
	 %s ||----w |\n\
	   ||	  ||\n\
 %s\n ", eyes, stoned, legs);
}

/*fonction qui crée et affiche la bulle de texte*/
void bulle (char *text){
	char top[100]="";
	char bot[100]="";
	/*passe sur chaque caractère de la liste et rajoute les contours*/
	for (int i = 0; strcmp(&text[i],"\0"); i++){
		strcat(top, "_");
		strcat(bot,"-");
	}
	/*affiche le texte avec le bon format*/
	printf(" %s\n<%s>\n %s\n", top, text, bot);
}

int main(int argc, char **argv) {
	char text[100] = "";
  	char eyes[3] = "00";
	char legs[100] = "";
	char stoned[2]=" ";
	int ret_val = parse_arguments(argc, argv, text, eyes, legs, stoned);
	if (ret_val == 0){
		bulle(text); /*affiche la bulle avec le texte*/
		affiche_vache(eyes, stoned, legs);
	}
	return ret_val;
}
