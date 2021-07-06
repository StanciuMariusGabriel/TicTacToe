#include "Game.h"

Game::Game(int dim, int combo)
{
	m_gameLogic = GameLogic(dim, combo);
}

void Game::RunGame()
{
	m_gameLogic.PrintGameBoard();
	int playerWin = 0;
	while (playerWin == 0)
	{
		if (m_gameLogic.CheckAllFilled())
			break;

		if (!m_gameLogic.GetPlayerTurn())
			std::cout << std::endl << "Player X" << std::endl;
		else
			std::cout << std::endl << "Player 0" << std::endl;

		int index1, index2;
		std::cout << "Row: ";
		std::cin >> index1;
		std::cout << "Column: ";
		std::cin >> index2;
		while (index1 < 0 || index1 >= m_gameLogic.GetSize() || index2 < 0 || index2 >= m_gameLogic.GetSize() || m_gameLogic.CheckPositionFill(index1, index2))
		{
			std::cout << "Place already used or out of bounds, choose another one" << std::endl;
			std::cout << "Row: ";
			std::cin >> index1;
			std::cout << "Column: ";
			std::cin >> index2;
		}

		playerWin = m_gameLogic.GameUpdate(index1, index2);
		m_gameLogic.PrintGameBoard();
	}
	WinnerMessage(playerWin);
}

void Game::WinnerMessage(int playerWin)
{
	switch (playerWin)
	{
	case 0:
		std::cout << std::endl << "No winner!" << std::endl;
		break;
	case 1:
		std::cout << std::endl << "Player X wins!" << std::endl;
		break;
	case 2:
		std::cout << std::endl << "Player 0 wins!" << std::endl;
		break;
	}
}


