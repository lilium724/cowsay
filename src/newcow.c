#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "showcow.h"

/*affiche la vache*/
int main(int argc, char **argv) {
	char text[100] = "";
  char eyes[3] = "00";
	int legs = 0;
	char tongue[3]="  ";
	char queue[100]="";
	int ret_val = parse_arguments(argc, argv, text, eyes, &legs, tongue, queue);
	if (ret_val == 0){
		bulle(text); /*affiche la bulle avec le texte*/
		affiche_vache(eyes, tongue, legs, queue);
	}
	return ret_val;
}
