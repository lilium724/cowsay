#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


void affiche_vache(char *eyes) {
	printf("\
   \\	^__^\n\
    \\	(%s)\\_______\n\
        (__)\\	    )\\/\\\n\
	   ||----w |\n\
	   ||	  ||\n", eyes);
}

int main(int argc, char **argv) {
	char text[100] = "";
  char eyes[3] = "00";
	parse_arguments(argc, argv, text, eyes);

	printf("%s\n", text);
  affiche_vache(eyes);
	return 0;
}
