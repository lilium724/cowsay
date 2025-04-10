#include <string.h>
#include <stdio.h>
#include <stdlib.h> /*ajout de stdlib pour utiliser atoi*/

/*tableau qui prend en compte toues les fotions de cow*/
char* list_arg[5] = {"-e", "--eyes", "-t", "--tall", "-s"}; 
int parse_arguments(int argc, char **argv, char *text, char eyes[static 3], char *legs, char *stoned) {
  int parse_text = 0;
  int verif = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(argv[i][0] != '-')
        parse_text = 1;
      else {
        /*vérifie que l'argument est valable*/
        for (int j=0; j<5 || 0 ; j++){ 
          if (!strcmp(argv[i], list_arg[j])){
            verif = 1;
          }
        }
        /*renvoie une erreur si l argument n'est pas valable, prédefinie dans list_arg*/
        if(verif == 0){
          fprintf(stderr, "L'option %s n'existe pas!\n", argv[i]);
          return 1;
        }
        else if(i == argc - 1) {
          fprintf(stderr, "L'option %s attend un argument!\n", argv[i]);
          return 1;
        }
        if(argv[i][1] == 'e' || !strcmp(argv[i], "--eyes")) {
          strncpy(eyes, argv[i+1], 2);
          eyes[3] = 0;
        }
        /*Option pour "Makes the cow appear thoroughly stoned."*/
        if(argv[i][1]=='s'){ 
          strncpy(eyes, "**",2); /*change les yeux de la vache*/
          eyes[3]=0;/*jsp à quoi set cette ligne mais vue qu'elle est au dessu je l'ai mise x)*/
          strncpy(stoned,"U\0",2);/*change la langue*/
          strcat(text, argv[argc-1]); /*Permet l'affichage du message ()*/
        }
        /*action qui rallonge les pied de la vache*/
        if (argv[i][1] == 't' || !strcmp(argv[i], "--tall")){ 
          for (int y = 0; y < atoi(argv[i+1]); y++){ /*atoi converti un le string en int*/
            strcat(legs, "          ||     ||\n ");/*ajoute un etage aux jambes*/
            }
        }
        

        i++;
      }
    }
    if(parse_text) {
      strcat(text, argv[argc-1]);
      if(i < argc - 1)
        strcat(text, " ");
    }
  }
  return 0;  
}
