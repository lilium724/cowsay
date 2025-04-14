#include <stdio.h>

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
