#include <string.h>
#include <stdio.h>
#include <stdlib.h> /*ajout de stdlib pour utiliser atoi*/

int parse_arguments(int argc, char **argv, char *text, char eyes[static 3], int *legs, char *tongue, int *queue) {
  int i;
  for(i = 1; i < argc; i++) {
    if(argv[i][0] != '-')
      break;

    /*Option pour les yeux */
    if((argv[i][1] == 'e' && !argv[i][2]) || !strcmp(argv[i], "--eyes")) {
      if(i == argc - 1) {
        fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
        return 1;
      }
          
      strncpy(eyes, argv[i+1], 2);
      eyes[3] = 0;
      i++;
    }

    /*Option pour "Makes the cow appear thoroughly stoned."*/
    else if(argv[i][1]=='s' && !argv[i][2]){ 
      strcpy(eyes, "**"); /*change les yeux de la vache*/
      strcpy(tongue,"U ");/*change la langue*/
    }

    /*Option qui rallonge les pied de la vache*/
    else if ((argv[i][1] == 't' && !argv[i][2]) || !strcmp(argv[i], "--tall")){ 
      if(i == argc - 1) {
        fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
        return 1;
      }
      *legs = atoi(argv[i+1]); 
      i++;
    }

    /*Option qui ralonge la queue de la vache*/
    else if (argv[i][1] == 'q' && !argv[i][2]){
      if(i == argc - 1) {
        fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
        return 1;
      }

      *queue = atoi(argv[i+1]);
      i++;
    }

    else {
      fprintf(stderr, "L'argument %s n'existe pas!\n", argv[i]);
      return 2;
    }
  }

  /*Le reste des arguments est traité comme du texte*/
  for(;i < argc; i++) {
    strcat(text, argv[i]);
    if(i < argc - 1)
      strcat(text, " ");
  }
  return 0;  
}
