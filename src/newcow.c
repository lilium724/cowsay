#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_vache() {
	puts("\
   \\   ^__^\n\
    \\  (00)\\_______\n\
       (__)\\       )\\/\\\n\
           ||----w |\n\
           ||     ||\n");
}

int main(int argc, char **argv) {
	affiche_vache();
	for (int i = 1; i < argc; i++) {
		
	}
	return 0;

}
