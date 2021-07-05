#include "Board.h"
#include <iostream>

Board::Board(int dim, int combo)
	:m_dim(dim), m_combo(combo)
{
	for (int index1 = 0; index1 < m_dim; ++index1)
	{
		std::vector<char> row;
		for (int index2 = 0; index2 < m_dim; ++index2)
			row.push_back('-');
		m_board.push_back(row);
	}
}

std::vector<std::vector<char>> Board::GetBoard() const
{
	return m_board;
}

void Board::SetBoard(std::vector<std::vector<char>> board)
{
	m_board = board;
}

void Board::PrintBoard() const
{
	for (int index1 = 0; index1 < m_dim; ++index1)
	{
		for (int index2 = 0; index2 < m_dim; ++index2)
			std::cout << " " << m_board[index1][index2] << " ";
		std::cout << std::endl;
	}
}


