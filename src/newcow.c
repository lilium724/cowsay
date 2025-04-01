#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


void affiche_vache() {
	puts("\
   \\	^__^\n\
    \\	(00)\\_______\n\
        (__)\\	    )\\/\\\n\
	   ||----w |\n\
	   ||	  ||\n");
}

int main(int argc, char **argv) {
	char text[100] = "";
  char eyes[2] = "00";
	parse_arguments(argc, argv, text, eyes);

	printf("%s\n", text);
  affiche_vache();
	return 0;
}
