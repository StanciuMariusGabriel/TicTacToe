#include <iostream>
#include "API/GameAPI.h"

#include "GameLogic.h"

using namespace tictactoe;

IGame::Game IGame::Produce(int dim, int combo)
{
	return std::make_shared<GameLogic>(dim, combo);
}