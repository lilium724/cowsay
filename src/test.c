#include <stdio.h>
#include <string.h>
#include "parser.h"

int test_parser(int argc, char **argv, char *text, char *eyes, char *legs, char *tongue) {
  char gText[100] = "";
  char gEyes[3] = "";
  char gTongue[3] = "";
  char gLegs[3];
  int errors = 0;
  parse_arguments(argc, argv, gText, gEyes, gLegs, gTongue);

  if(text && strcmp(gText, text)) {
    printf("Expected\n %s\nGot\n%s\n", text, gText);
    errors++;
  }
  if(eyes && strcmp(gEyes, eyes)) {
    printf("Expected %s, got %s\n", eyes, gEyes);
    errors++;
  }
  if(legs && strcmp(gLegs, legs)) {
    printf("Expected %s, got %s\n", legs, gLegs);  
    errors++;
  }
  if(tongue && strcmp(gTongue, tongue)) {
    printf("Expected %s, got %s\n", tongue, gTongue);
    errors++;
  }

  return errors;
}

int main() {
  puts("Testing parser.h...");
  int errors = 0;

  const char *argv[] = {"", "Hello", "World"};
  errors += test_parser(3, argv, "Hello World", NULL, NULL, NULL);

  if(!errors) {
    puts("All good!");
  }
  return errors;
}
