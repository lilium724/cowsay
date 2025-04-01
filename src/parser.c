#include <string.h>
#include <stdio.h>

int parse_arguments(int argc, char **argv, char *text, char *eyes) {
  int parse_text = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(argv[i][0] != '-')
        parse_text = 1;
      else {
        if(argv[i][1] == 'e' || !strcmp(argv[i], "--eyes")) {
          //TODO: eyes option parser
        }

        i++;
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
