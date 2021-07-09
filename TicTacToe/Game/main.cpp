#include <iostream>

#include "Game.h"

using namespace tictactoe;
int main()
{
	Game game = Game(3, 3);
	game.RunGame();
}