#include <iostream>
#include "Game.h"

int main()
{
	int dim, combo;
	dim = 3;
	combo = 3;
	Game game = Game(dim, combo);
	game.RunGame();
}