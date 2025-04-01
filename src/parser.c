#include <string.h>

int parse_arguments(int argc, char **argv, char *text, char *eyes) {
  int parse_text = 0;
  for(int i = 1; i < argc; i++) {
    if(!parse_text) {
      if(strncmp(argv[i], "-", 1))
        parse_text = 1;
      else
        i++;
    }
    if(parse_text) {
      strcat(text, argv[i]);
      if(i < argc - 1)
        strcat(text, " ");
    }
  }
  return 0;  
}
