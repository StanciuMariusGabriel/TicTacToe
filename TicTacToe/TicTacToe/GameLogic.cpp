#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic(int dim, int combo)
{
	m_gameBoard = Board(dim, combo);
	m_playerTurn = false;
	m_playerWin = 0;
}

void GameLogic::StartGame()
{
	m_gameBoard.PrintBoard();
	while (m_playerWin == 0)
	{
		if (!m_playerTurn)
			std::cout << std::endl << "Player X" << std::endl;
		else
			std::cout << std::endl << "Player 0" << std::endl;

		std::vector<std::vector<char>> board = m_gameBoard.GetBoard();

		int index1, index2;
		std::cout << "Row: ";
		std::cin >> index1;
		std::cout << "Column: ";
		std::cin >> index2;
		while (index1 < 0 || index1 >= board.size() || index2 < 0 || index2 >= board.size() || board[index1][index2] != '-')
		{
			std::cout << "Place already used or out of bounds, choose another one" << std::endl;
			std::cout << "Row: ";
			std::cin >> index1;
			std::cout << "Column: ";
			std::cin >> index2;
		}

		if (!m_playerTurn)
			board[index1][index2] = 'X';
		else
			board[index1][index2] = '0';

		m_gameBoard.SetBoard(board);
		m_gameBoard.PrintBoard();

		if (CheckPlayerWin(index1, index2, board))
			if (!m_playerTurn)
			{
				std::cout << std::endl << "Player X Wins" << std::endl;
				m_playerWin = 1;
			}
			else
			{
				std::cout << std::endl << "Player 0 Wins" << std::endl;
				m_playerWin = 2;
			}
		m_playerTurn = !m_playerTurn;
	}
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
					if (combo >= m_gameBoard.GetCombo())
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
				if (combo >= m_gameBoard.GetCombo())
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
