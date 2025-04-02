#include <string.h>
#include <stdio.h>

int parse_arguments(int argc, char **argv, char *text, char eyes[static 3]) {
  int parse_text = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(argv[i][0] != '-')
        parse_text = 1;
      else {
        if(argv[i][1] == 'e' || !strcmp(argv[i], "--eyes")) {
          if(i == argc - 1) {
            fprintf(stderr, "L'option -e attend un argument!\n");
            return 1;
          }
          strncpy(eyes, argv[i+1], 2);
          eyes[3] = 0;
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
