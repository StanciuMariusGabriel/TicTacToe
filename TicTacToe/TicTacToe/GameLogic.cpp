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
			std::cout << std::endl << "Player 1" << std::endl;
		else
			std::cout << std::endl << "Player 2" << std::endl;

		std::vector<std::vector<char>> board = m_gameBoard.GetBoard();

		int index1, index2;
		while (board[index1][index2] != '-')
		{
			std::cout << "Row: ";
			std::cin >> index1;
			std::cout << "Column: ";
			std::cin >> index2;
		}
		m_playerTurn = !m_playerTurn;
	}
}

bool GameLogic::CheckPlayerWin(int index1, int index2, std::vector<std::vector<char>> board)
{
	return false;
}


