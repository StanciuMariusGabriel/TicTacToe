#pragma once

#include <vector>

class Board
{
public:
	Board(int dim);

	int GetBoardSize() const;
	char GetElementAt(int index1, int index2) const;
	void SetElementAt(char elem, int index1, int index2);

	bool CheckPlayerWin(int index1, int index2, int combo);

private:
	std::vector<std::vector<char>> m_board;
};