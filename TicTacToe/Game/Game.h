#pragma once
#include <iostream>
#include "GameLogic.h"

class Game
{
private:
	GameLogic m_gameLogic;

public:
	Game() = default;
	Game(int dim, int combo);
	void RunGame();
	void WinnerMessage(int playerWin);
};