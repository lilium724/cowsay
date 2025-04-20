#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "showcow.h"

int main(int argc, char **argv) {
  if(argc != 2) {
    fprintf(stderr, "Usage: %s nom_du_fichier", argv[0]);
    return 1;
  }

  FILE *f = fopen(argv[1], "r");
  if(!f) {
    fprintf(stderr, "%s n'a pas pu être ouvert en mode lecture!", argv[1]);
    return 2;
  }

  Parameters param = default_parameters();

  fscanf(f, "%c", param.tongue);


  while(!feof(f)) {
    
    //Si le caractère est un retour à la ligne, on passe directement au suivant.
    if(param.tongue[0] == '\n') {
      fscanf(f, "%c", param.tongue);
      continue;
    }
    update();
    bulle(&param);
    affiche_vache(&param);
    
    //On concatène te paramêtre texte en ajoutant le premier caractère dans tongue
    //Comme text à été initialisé à 0, on a pas besoin de se préocupper de terminer la concaténation avec 0;
    strncat(param.text, param.tongue, 1);

    usleep(100000);

    //scanne le prochain caractère du fichier, et le store au 1er indice de la chaine tongue
    fscanf(f, "%c", param.tongue);
  }
  update();
  bulle(&param);
  affiche_vache(&param);
}
