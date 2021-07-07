#include "Game.h"
#include <iostream>

using namespace tictactoe;

Game::Game(int dim, int combo)
{
	m_gameLogic = IGame::Produce(dim, combo);
}

void Game::PrintGameBoard() const
{
	for (int index1 = 0; index1 < m_gameLogic->GetBoardSize(); ++index1)
	{
		for (int index2 = 0; index2 < m_gameLogic->GetBoardSize(); ++index2)
			std::cout << " " << m_gameLogic->GetElementAt(index1, index2) << " ";
		std::cout << std::endl;
	}
}

void Game::RunGame()
{
	PrintGameBoard();

	EGameState gameState = m_gameLogic->GetState();
	EMoveResult moveResult;
	
	while (gameState == EGameState::Playing)
	{
		if (m_gameLogic->GetActivePlayer() == 1)
			std::cout << std::endl << "Player X" << "\n\n";
		else
			std::cout << std::endl << "Player 0" << "\n\n";

		int index1, index2;

		std::cout << "Row: ";
		std::cin >> index1;
		std::cout << "Column: ";
		std::cin >> index2;
		std::cout << std::endl;

		moveResult = m_gameLogic->MakeMove(index1, index2);
		while (moveResult != EMoveResult::Success)
		{
			std::cout << std::endl << "Place already used or out of bounds, choose another one" << "\n\n";
			std::cout << "Row: ";
			std::cin >> index1;
			std::cout << "Column: ";
			std::cin >> index2;
		}

		gameState = m_gameLogic->GetState();	
		PrintGameBoard();
	}
	WinnerMessage(gameState);
}

void Game::WinnerMessage(EGameState gameState)
{
	switch (gameState)
	{
	case EGameState::Draw:
		std::cout << std::endl << "No winner!" << std::endl;
		break;
	case EGameState::Player1Win:
		std::cout << std::endl << "Player X wins!" << std::endl;
		break;
	case EGameState::Player2Win:
		std::cout << std::endl << "Player 0 wins!" << std::endl;
		break;
	}
}


