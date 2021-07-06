#include "Game.h"

Game::Game(int dim, int combo)
	: m_gameLogic(dim, combo)
{

}

void Game::PrintGameBoard() const
{
	for (int index1 = 0; index1 < m_gameLogic.GetBoardSize(); ++index1)
	{
		for (int index2 = 0; index2 < m_gameLogic.GetBoardSize(); ++index2)
			std::cout << " " << m_gameLogic.GetElementAt(index1, index2) << " ";
		std::cout << std::endl;
	}
}

void Game::RunGame()
{
	PrintGameBoard();

	EGameState gameState = EGameState::DRAW;
	
	while (gameState == 0)
	{
		if (m_gameLogic.IsBoardFull())
			break;

		if (!m_gameLogic.GetPlayerTurn())
			std::cout << std::endl << "Player X" << "\n\n";
		else
			std::cout << std::endl << "Player 0" << "\n\n";

		int index1, index2;

		std::cout << "Row: ";
		std::cin >> index1;
		std::cout << "Column: ";
		std::cin >> index2;
		std::cout << std::endl;
		while (index1 < 0 || index1 >= m_gameLogic.GetBoardSize() || index2 < 0 || index2 >= m_gameLogic.GetBoardSize() || m_gameLogic.IsPositionFilled(index1, index2))
		{
			std::cout << std::endl << "Place already used or out of bounds, choose another one" << "\n\n";
			std::cout << "Row: ";
			std::cin >> index1;
			std::cout << "Column: ";
			std::cin >> index2;
		}

		gameState = m_gameLogic.MakeMove(index1, index2);
		PrintGameBoard();
	}
	WinnerMessage(gameState);
}

void Game::WinnerMessage(int playerWin)
{
	switch (playerWin)
	{
	case EGameState::DRAW:
		std::cout << std::endl << "No winner!" << std::endl;
		break;
	case EGameState::PLAYER1_WIN:
		std::cout << std::endl << "Player X wins!" << std::endl;
		break;
	case EGameState::PLAYER2_WIN:
		std::cout << std::endl << "Player 0 wins!" << std::endl;
		break;
	}
}


