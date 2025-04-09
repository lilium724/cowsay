#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"


void affiche_vache(char *eyes, char *legs) {
	printf("\
   \\	^__^\n\
    \\	(%s)\\_______\n\
        (__)\\	    )\\/\\\n\
	   ||----w |\n\
	   ||	  ||\n\
 %s\n ", eyes, legs);
}

int main(int argc, char **argv) {
	char text[100] = "";
  	char eyes[3] = "00";
	char legs[100] = "";
	int ret_val = parse_arguments(argc, argv, text, eyes, legs);
	if (ret_val == 0){
		printf("%s\n", text);
		affiche_vache(eyes, legs);
	}
	return ret_val;
}
