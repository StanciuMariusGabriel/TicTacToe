#pragma once
#include "Board.h"


enum EGameState
{
	DRAW,
	PLAYER1_WIN,
	PLAYER2_WIN
};

class GameLogic
{
public:
	GameLogic(int dim, int combo);

	int GetBoardSize() const;
	char GetElementAt(int index1, int index2) const;
	bool GetPlayerTurn() const;
	
	EGameState MakeMove(int index1, int index2);
	bool IsPositionFilled(int index1, int index2) const;
	bool IsBoardFull() const;

private:
	Board m_gameBoard;

	bool m_playerTurn;
	EGameState m_gameState;
	int m_combo;
};