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
    if(param.tongue[0] == '\n') {
      fscanf(f, "%c", param.tongue);
      continue;
    }
    update();
    bulle(&param);
    affiche_vache(&param);
    strncat(param.text, param.tongue, 1);
    usleep(100000);
    fscanf(f, "%c", param.tongue);
  }
  update();
  bulle(&param);
  affiche_vache(&param);
}
