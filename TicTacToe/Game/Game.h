#pragma once

#include "GameAPI.h"

class Game
{
public:
	Game() = default;
	Game(int dim, int combo);

	void PrintGameBoard() const;
	void RunGame();
	void WinnerMessage(tictactoe::EGameState gameState);

private:
	tictactoe::IGame::Game m_gameLogic;
};