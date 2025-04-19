#pragma once

#define DEF_TEXT ""
#define DEF_EYES "00"
#define DEF_TONGUE "  "
#define DEF_TAIL 0
#define DEF_LEGS 0

typedef struct parameters {
	char text[100];
	char eyes[3];
	char tongue[3];
	int legs;
	int tail;
} Parameters;

Parameters default_parameters();

int parse_arguments(int argc, char **argv, Parameters *param);
