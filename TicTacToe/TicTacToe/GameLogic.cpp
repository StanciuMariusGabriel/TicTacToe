#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic(int dim, int combo)
	:m_combo(combo)
{
	m_gameBoard = Board(dim);
	m_playerTurn = false;
	m_playerWin = 0;
}

int GameLogic::GameMoveUpdate(int index1, int index2)
{
	std::vector<std::vector<char>> board = m_gameBoard.GetBoard();

	if (!m_playerTurn)
		board[index1][index2] = 'X';
	else
		board[index1][index2] = '0';

	m_gameBoard.SetBoard(board);

	if (CheckPlayerWin(index1, index2, board))
		if (!m_playerTurn)
			m_playerWin = 1;
		else
			m_playerWin = 2;
	m_playerTurn = !m_playerTurn;

	return m_playerWin;
}

bool GameLogic::CheckPlayerWin(int index1, int index2, std::vector<std::vector<char>> board)
{
	/*char symbol;
	if (!m_playerTurn)
		symbol = 'X';
	else
		symbol = '0';*/
	int combo = 0, row_index = index1, col_index = index2, dir = 0;

	while (dir != 8)
	{
		if (row_index >= 0 && row_index < board.size() && col_index >= 0 && col_index < board.size())
		{
			if (board[row_index][col_index] == board[index1][index2])
				++combo;
			else
			{
				++dir;
				row_index = index1;
				col_index = index2;
				if (dir % 2 == 0)
				{
					if (combo >= m_combo)
						return true;
					else
						combo = 1;
				}
			}
		}
		else
		{
			++dir;
			row_index = index1;
			col_index = index2;
			if (dir % 2 == 0)
			{
				if (combo >= m_combo)
					return true;
				else
					combo = 1;
			}
		}
		switch (dir)
		{
		case 0:
			++row_index;
			break;
		case 1:
			--row_index;
			break;
		case 2:
			--col_index;
			break;
		case 3:
			++col_index;
			break;
		case 4:
			--row_index;
			--col_index;
			break;
		case 5:
			++col_index;
			++row_index;
			break;
		case 6:
			--col_index;
			++row_index;
			break;
		case 7:
			++col_index;
			--row_index;
			break;
		default:
			return false;
		}
	}
	return false;
}

bool GameLogic::GetPlayerTurn() const
{
	return m_playerTurn;
}

int GameLogic::GetSize() const
{
	return m_gameBoard.GetBoardSize();
}

void GameLogic::PrintGameBoard() const
{
	m_gameBoard.PrintBoard();
}

bool GameLogic::CheckPositionFill(int index1, int index2)
{
	return m_gameBoard.GetBoard()[index1][index2] != '-';
}

bool GameLogic::CheckAllFilled()
{
	std::vector<std::vector<char>> board = m_gameBoard.GetBoard();
	for (int index1 = 0; index1 < GetSize(); ++index1)
		for (int index2 = 0; index2 < GetSize(); ++index2)
			if (board[index1][index2] == '-')
				return false;
	return true;
}
