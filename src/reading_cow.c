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

  char tongue[3] = "  ";
  fscanf(f, "%c", tongue);
  char text[100] = "";
  while(!feof(f)) {
    if(tongue[0] == '\n') {
      fscanf(f, "%c", tongue);
      continue;
    }
    update();
    bulle(text);
    affiche_vache("00", tongue, 0, "");
    strncat(text, tongue, 1);
    usleep(100000);
    fscanf(f, "%c", tongue);
  }
  update();
  bulle(text);
  affiche_vache("00", "  ", 0, "");
}
