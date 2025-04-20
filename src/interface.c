#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "showcow.h"

Parameters param;

const char* const happy_cow[] = {
	"Hi! I'm Gochi! Gochi the cow :)",
	"I love rolling around in the grass!",
	"One day, I'll learn how to ride a bicycle. That's my dream!",
	"You're my best friend!",
	0
};

const char* const sad_cow[] = {
	"I don't feel so good",
	"Are you mad at me ?",
	"I'm sorry",
	"What did I do wrong ?",
	"Why do you hate me ?",
	"Please forgive me",
	0
};

void get_back_here(int sig) {
	puts("");
	puts("Get back here. There's only one way out of this game.");
	fputs("lunchfood ?>", stdout);
	fflush(stdout);
}

void init_game() {
	param = default_parameters();
	srand(time(NULL));
	signal(SIGINT, get_back_here);
}

void show_gochi(int fitness) {
	static int happy_pointer = 0, sad_pointer = 0;

	if (fitness >= 4 && fitness <= 6) {
		strcpy(param.text, happy_cow[happy_pointer++]);
		if(!happy_cow[happy_pointer])
			happy_pointer = 0;
		strcpy(param.eyes, "00");
	} else {
		strcpy(param.text, sad_cow[sad_pointer++]);
		if(!sad_cow[sad_pointer])
			sad_pointer = 0;
		strcpy(param.eyes, "><");
	}
	update();
	bulle(&param);
	affiche_vache(&param);
}

int ask_lunchfood(int stock) {
	int i;
	printf("stock = %d. lunchfood? >", stock);
	int res = scanf(" %d", &i);

	while(!res || i < 0 || i > stock) {	
		if(!res)
			puts("Is this funny to you ?");
		else if(i < 0)
			puts("You monster");
		else
			puts("You don't have enough stock for that. You incompetent monster");
		
		while ((getchar()) != '\n');
		printf("stock = %d. lunchfood? >", stock);
		res = scanf(" %d", &i);
	}
	return i;
}

void roll_dice(int *digestion, int *crop) {
	*digestion = -(rand() % 4);
	*crop = (rand() % 7) - 3;
}

void game_over(int score) {
	update();
	strcpy(param.text, "I stil... love... you...");
	strcpy(param.eyes, "xx");
	strcpy(param.tongue, "U ");
	bulle(&param);
	affiche_vache(&param);
	puts("You killed her. That cow trusted you with her life, and you killed her");
	puts("You're a cold-blooded killer");
	printf("Your score: %d\n Good job!\n", score);
}
