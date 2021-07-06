#include <iostream>
#include "Game.h"

int main()
{
	int dim, combo;
	dim = 5;
	combo = 3;
	Game game = Game(dim, combo);
	game.RunGame();
}