#include <string.h>
#include <stdio.h>
#include <stdlib.h> /*ajout de stdlib pour utiliser atoi*/
#include "parser.h"

Parameters default_parameters() {
  Parameters def = {DEF_TEXT, DEF_EYES, DEF_TONGUE, DEF_LEGS, DEF_TAIL};
  return def;
}

int parse_arguments(int argc, char **argv, Parameters *param) {
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
          
      strncpy(param->eyes, argv[i+1], 2);
      param->eyes[2] = 0;
      i++;
    }

    /*Option pour "Makes the cow appear thoroughly stoned."*/
    else if(argv[i][1]=='s' && !argv[i][2]){ 
      strcpy(param->eyes, "**"); /*change les yeux de la vache*/
      strcpy(param->tongue,"U ");/*change la langue*/
    }

    /*Option qui rallonge les pied de la vache*/
    else if ((argv[i][1] == 't' && !argv[i][2]) || !strcmp(argv[i], "--tall")){ 
      if(i == argc - 1) {
        fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
        return 1;
      }
      param->legs = atoi(argv[i+1]); 
      i++;
    }

    /*Option qui ralonge la queue de la vache*/
    else if (argv[i][1] == 'q' && !argv[i][2]){
      if(i == argc - 1) {
        fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
        return 1;
      }

      param->tail = atoi(argv[i+1]);
      i++;
    }

    else {
      fprintf(stderr, "L'option %s n'existe pas!\n", argv[i]);
      return 2;
    }
  }

  /*Le reste des arguments est traité comme du texte*/
  for(;i < argc; i++) {
    strcat(param->text, argv[i]);
    if(i < argc - 1)
      strcat(param->text, " ");
  }
  return 0;  
}
