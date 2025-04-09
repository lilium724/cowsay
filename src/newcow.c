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
	int ret_val = parse_arguments(argc, argv, text, eyes);
	if (ret_val == 0){
		printf("%s\n", text);
		affiche_vache(eyes);
	}
	return ret_val;
}
