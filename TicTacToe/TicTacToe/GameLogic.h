#pragma once
#include "Board.h"

class GameLogic
{
private:
	Board m_gameBoard;
	bool m_playerTurn;
	int m_playerWin;
public:
	GameLogic(int dim, int combo);
	void StartGame();
	bool CheckPlayerWin(int index1, int index2, std::vector<std::vector<char>> board);
};