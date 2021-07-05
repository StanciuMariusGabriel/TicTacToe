#pragma once
#include <vector>

class Board
{
private:
	int m_dim;
	int m_combo;
	std::vector<std::vector<char>> m_board;

public:
	Board() = default;
	Board(int dim, int combo);
	std::vector<std::vector<char>> GetBoard() const;
	void SetBoard(std::vector<std::vector<char>> board);
	void PrintBoard() const;

};