#include <stdio.h>
#include <string.h>
#include "parser.h"

void print_command_line(int argc, char **argv) {
  fprintf(stderr, "Error with command: ");
  for(int i = 0; i < argc; i++) {
    fprintf(stderr, "%s ", argv[i]);
  }
  fprintf(stderr, "\n");
}

/*taite les options entrée en paramètre lorsque l'on lance le programe ./newcow
et permet l'affichage voule de la vache*/
int test_parser(int argc, char **argv, char *text, char *eyes, int legs, char *tongue, int tail) {
  Parameters param = default_parameters();
  int errors = 0;
  parse_arguments(argc, argv, &param);

  if(text && strcmp(param.text, text)) {
    print_command_line(argc, argv);
    printf("text: Expected\n %s\nGot\n%s\n", text, param.text);
    errors++;
  }
  if(eyes && strcmp(param.eyes, eyes)) {
    print_command_line(argc, argv);
    printf("eyes: Expected %s, got %s\n", eyes, param.eyes);
    errors++;
  }
  if((legs >= 0) && legs != param.legs) {
    print_command_line(argc, argv);
    printf("legs: Expected %d, got %d\n", legs, param.legs);  
    errors++;
  }
  if(tongue && strcmp(param.tongue, tongue)) {
    print_command_line(argc, argv);
    printf("tongue: Expected %s, got %s\n", tongue, param.tongue);
    errors++;
  }
  if((tail >= 0) && tail != param.tail) {
    print_command_line(argc, argv);
    printf("tail: Expected %d, got %d\n", tail, param.tail);
    errors++;
  }

  return errors;
}


//AJOUTER LES TESTS ICI
//char *argv_2[] = {"nom_du_programme", "arg1", "arg2", ...};
//errors += test_parser(taille_de_argv_2, argv_2, "Resultat attendu pour text", "resultat attendu pour eyes", ...);
//(laissez NULL pour le string ou -1 pour un int si vous voulez skip le test pour cette valeur)
int main() {
  puts("");
  puts("Testing parser.c...");
  int errors = 0;

  char *argv[10] = {"newcow"};

  argv[1] = "Hello"; argv[2] = "World";
  errors += test_parser(3, argv, "Hello World", NULL, -1, NULL, -1);

  argv[1] = "-e"; argv[2] = "ee"; argv[3] = "salut";
  errors += test_parser(4, argv, "salut", "ee", -1, NULL, -1);
  
  argv[1] = "-q"; argv[2] = "10";
  errors += test_parser(3, argv, NULL, NULL, -1, NULL, 10);

  argv[1] = "hello"; argv[2] = "-e"; argv[3] = "00";
  errors += test_parser(4, argv, "hello -e 00", DEF_EYES, -1, NULL, -1);

  if(!errors) {
    puts("All unit tests passed!");
  }
  return errors;
}
