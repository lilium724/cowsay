#include <string.h>
#include <stdio.h>
#include <stdlib.h> /*ajout de stdlib pour utiliser atoi*/

/*tableau qui prend en compte toues les fotions de cow*/
char* list_arg[4] = {"-e", "--eyes", "-t", "--tall"}; 
int parse_arguments(int argc, char **argv, char *text, char eyes[static 3], char *legs) {
  int parse_text = 0;
  int verif = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(argv[i][0] != '-')
        parse_text = 1;
      else {
        /*vérifie que le premiers argument est valable*/
        for (int j=0; j<4 || 0 ; j++){ 
          if (!strcmp(argv[i], list_arg[j])){
            verif = 1;
          }
        }
        /*renvoie une erreur si l argument n est pas valable prédefinie dans list_arg*/
        if(verif == 0){
          fprintf(stderr, "L'option %s n'existe pas!\n", argv[i]);
          return 1;
        }
        else if(i == argc - 1) {
          fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
          return 1;
        }
        else if(argv[i][1] == 'e' || !strcmp(argv[i], "--eyes")) {
          strncpy(eyes, argv[i+1], 2);
          eyes[3] = 0;
        }
        /*action qui rallonge les pied de la vache*/
        else if (argv[i][1] == 't' || !strcmp(argv[i], "--tall")){ 
          for (int y = 0; y < atoi(argv[i+1]); y++){ /*atoi converti un le string en int*/
            strcat(legs, "          ||	  ||\n ");
            }
        }
        

        i++;
      }
    }
    if(parse_text) {
      strcat(text, argv[i]);
      if(i < argc - 1)
        strcat(text, " ");
    }
  }
  return 0;  
}
