#include <string.h>
#include <stdio.h>
#include <stdlib.h> /*ajout de stdlib pour utiliser atoi*/

int parse_arguments(int argc, char **argv, char *text, char eyes[static 3], int *legs, char *tongue, char *queue) {
  int parse_text = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(argv[i][0] != '-'){
        parse_text = 1;
      }
      else {
        if(argv[i][1] == 'e' || !strcmp(argv[i], "--eyes")) {
          if(i == argc - 1) {
            fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
            return 1;
          }
          
          strncpy(eyes, argv[i+1], 2);
          eyes[3] = 0;

          i++;
        }
        /*Option pour "Makes the cow appear thoroughly stoned."*/
        else if(argv[i][1]=='s'){ 
          strcpy(eyes, "**"); /*change les yeux de la vache*/
          strcpy(tongue,"U ");/*change la langue*/
        }
        /*action qui rallonge les pied de la vache*/
        else if (argv[i][1] == 't' || !strcmp(argv[i], "--tall")){ 
          if(i == argc - 1) {
            fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
            return 1;
          }
         *legs = atoi(argv[i+1]); 
          i++;
        }
        else if (argv[i][1] == 'q'){
          if(i == argc - 1) {
            fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
            return 1;
          }

          for (int y = 0; y<atoi(argv[i+1]); y++){
            if (y%2 == 1){
              strcat(queue,"\\");
            }
            else{
              strcat(queue, "/");
            }
          }
          i++;
        }
        else {
          fprintf(stderr, "L'argument %s n'existe pas!", argv[i]);
          return 2;
        }

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
