#pragma once
#include <vector>

class Board
{
private:
	std::vector<std::vector<char>> m_board;

public:
	Board() = default;
	Board(int dim);
	std::vector<std::vector<char>> GetBoard() const;
	void SetBoard(std::vector<std::vector<char>> board);
	void PrintBoard() const;
	int GetBoardSize() const;
};