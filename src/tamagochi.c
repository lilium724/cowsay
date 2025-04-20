#include "interface.h"

int fitness = 5;
int stock = 5;

int game_loop() {
	int days = 0;
	int digestion = 0, crop = 0;

	while(fitness > 0 && fitness < 10) {
		show_gochi(fitness);
		int lunchfood = ask_lunchfood(stock);

		roll_dice(&digestion, &crop);

		fitness += (lunchfood + digestion);
		stock += (crop - lunchfood);
		stock = (stock > 10) ? 10 : (stock < 0) ? 0 : stock;

		days++;
	}

	return days;
}

int main() {
	init_game();
	int score = game_loop();

	game_over(score);
	return 0;
}
