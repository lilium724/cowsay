#include <stdio.h>
#include <string.h>
#include "parser.h"

/*taite les options entrée en paramètre lorsque l'on lance le programe ./newcow
et permet l'affichage voule de la vache*/
int test_parser(int argc, char **argv, char *text, char *eyes, int legs, char *tongue, char *queue) {
  char gText[100] = "";
  char gEyes[3] = "";
  char gTongue[3] = "";
  int gLegs;
  char gQueue[100] = "";
  int errors = 0;
  parse_arguments(argc, argv, gText, gEyes, &gLegs, gTongue, gQueue);

  if(text && strcmp(gText, text)) {
    printf("Expected\n %s\nGot\n%s\n", text, gText);
    errors++;
  }
  if(eyes && strcmp(gEyes, eyes)) {
    printf("Expected %s, got %s\n", eyes, gEyes);
    errors++;
  }
  if((legs >= 0) && legs == gLegs) {
    printf("Expected %d, got %d\n", legs, gLegs);  
    errors++;
  }
  if(tongue && strcmp(gTongue, tongue)) {
    printf("Expected %s, got %s\n", tongue, gTongue);
    errors++;
  }
  if(queue && strcmp(gQueue, queue)) {
    printf("Expected %s, got %s\n", queue, gQueue);
    errors++;
  }

  return errors;
}

//AJOUTER LES TESTS ICI
//char *argv_2[] = {"nom_du_programme", "arg1", "arg2", ...};
//errors += test_parser(taille_de_argv_2, argv_2, "Resultat attendu pour text", "resultat attendu pour eyes", ...);
//(laissez NULL pour le string ou -1 pour un int si vous voulez skip le test pour cette valeur)
int main() {
  puts("Testing parser.c...");
  int errors = 0;

  char *argv[10] = {"newcow"};

  argv[1] = "Hello"; argv[2] = "World";
  errors += test_parser(3, argv, "Hello World", NULL, -1, NULL, NULL);
  argv[1] = "-e"; argv[2] = "ee"; argv[3] = "salut";
  errors += test_parser(4, argv, "salut", "ee", -1, NULL, NULL);


  if(!errors) {
    puts("All good!");
  }
  return errors;
}
