#include "GameLogic.h"
#include <iostream>

using namespace tictactoe;

GameLogic::GameLogic(int dim, int combo)
	: m_combo(combo)
	, m_gameBoard(dim)
	, m_activePlayer(1)
	, m_gameState(EGameState::Playing)
{ }

EMoveResult GameLogic::MakeMove(int index1, int index2)
{
	if (index1 < 0 || index1 >= GetBoardSize() || index2 < 0 || index2 >= GetBoardSize())
		return EMoveResult::Invalid;

	if (IsPositionFilled(index1, index2))
		return EMoveResult::PositionOccupied;

	if (m_activePlayer == 1)
		m_gameBoard.SetElementAt('X', index1, index2);
	else
		m_gameBoard.SetElementAt('0', index1, index2);

	UpdateState(index1, index2, m_combo);

	m_activePlayer = 3 - m_activePlayer;

	return EMoveResult::Success;
}

EGameState tictactoe::GameLogic::GetState() const
{
	return m_gameState;
}

void tictactoe::GameLogic::UpdateState(int index1, int index2, int m_combo)
{
	if (m_gameBoard.CheckPlayerWin(index1, index2, m_combo))
		if (m_activePlayer == 1)
			m_gameState = EGameState::Player1Win;
		else
			m_gameState = EGameState::Player2Win;
	else if (IsBoardFull())
		m_gameState = EGameState::Draw;
	else
		m_gameState = EGameState::Playing;
}

int GameLogic::GetActivePlayer() const
{
	return m_activePlayer;
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
