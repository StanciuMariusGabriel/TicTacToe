#include "GameLogic.h"
#include <iostream>

GameLogic::GameLogic(int dim, int combo)
	: m_combo(combo)
	, m_gameBoard(dim)
	, m_playerTurn(false)
	, m_gameState(EGameState::DRAW)
{ }

EGameState GameLogic::MakeMove(int index1, int index2)
{
	if (!m_playerTurn)
		m_gameBoard.SetElementAt('X', index1, index2);
	else
		m_gameBoard.SetElementAt('0', index1, index2);

	if (m_gameBoard.CheckPlayerWin(index1, index2, m_combo))
		if (!m_playerTurn)
			m_gameState = EGameState::PLAYER1_WIN;
		else
			m_gameState = EGameState::PLAYER2_WIN;

	m_playerTurn = !m_playerTurn;

	return m_gameState;
}

bool GameLogic::GetPlayerTurn() const
{
	return m_playerTurn;
}

int GameLogic::GetBoardSize() const
{
	return m_gameBoard.GetBoardSize();
}

char GameLogic::GetElementAt(int index1, int index2) const
{
	return m_gameBoard.GetElementAt(index1, index2);
}

bool GameLogic::IsPositionFilled(int index1, int index2) const
{
	return m_gameBoard.GetElementAt(index1, index2) != '-';
}

bool GameLogic::IsBoardFull() const
{
	for (int index1 = 0; index1 < GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < GetBoardSize(); ++index2)
			if (m_gameBoard.GetElementAt(index1, index2) == '-')
				return false;
	return true;
}
