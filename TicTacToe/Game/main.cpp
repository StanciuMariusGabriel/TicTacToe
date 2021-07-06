#include <iostream>
#include "GameLogic.h"

int main()
{
	int dim, combo;
	dim = 5;
	combo = 3;
	GameLogic game = GameLogic(dim, combo);
	game.StartGame();
}