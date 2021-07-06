#pragma once
#include "Board.h"

class GameLogic
{
private:
	Board m_gameBoard;
	bool m_playerTurn;
	int m_playerWin;
	int m_combo;
public:
	GameLogic() = default;
	GameLogic(int dim, int combo);
	int GameMoveUpdate(int index1, int index2);
	bool CheckPlayerWin(int index1, int index2, std::vector<std::vector<char>> board);
	bool GetPlayerTurn() const;
	int GetSize() const;
	void PrintGameBoard() const;
	bool CheckPositionFill(int index1, int index2);
	bool CheckAllFilled();
};