#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "showcow.h"

/*affiche la vache*/
int main(int argc, char **argv) {
	Parameters param = default_parameters();
	int ret_val = parse_arguments(argc, argv, &param);
	if (ret_val == 0){
		bulle(&param); /*affiche la bulle avec le texte*/
		affiche_vache(&param);
	}
	return ret_val;
}
