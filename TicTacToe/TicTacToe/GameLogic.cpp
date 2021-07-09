#include "GameLogic.h"
#include <iostream>

using namespace tictactoe;

GameLogic::GameLogic(int dim, int combo)
	: m_combo(combo)
	, m_gameBoard(dim)
	, m_activePlayer(1)
	, m_gameState(EGameState::Playing)
	, m_singlePlayer(false)
	, m_userPlayerNumber(1)
	, m_computerStrategy(std::make_shared<EasyStrategy>())
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

	if (m_singlePlayer && m_gameState == EGameState::Playing)
		MakeComputerMove();

	return EMoveResult::Success;
}

int tictactoe::GameLogic::GetSinglePlayerUserNumber() const
{
	return m_userPlayerNumber;
}

bool tictactoe::GameLogic::IsSinglePlayer() const
{
	return m_singlePlayer;
}

void tictactoe::GameLogic::SetSinglePlayer(int userPlayerNumber)
{
	m_singlePlayer = true;
	m_userPlayerNumber = userPlayerNumber;
	if (userPlayerNumber == 2)
		MakeComputerMove();
}

void tictactoe::GameLogic::SetMultiPlayer()
{
	m_singlePlayer = false;
}

void tictactoe::GameLogic::MakeComputerMove()
{
	std::pair<int, int> move = m_computerStrategy->ComputerMove(m_gameBoard, m_activePlayer, m_combo);

	if (m_activePlayer == 1)
		m_gameBoard.SetElementAt('X', move.first, move.second);
	else
		m_gameBoard.SetElementAt('0', move.first, move.second);

	UpdateState(move.first, move.second, m_combo);

	m_activePlayer = 3 - m_activePlayer;

}

EGameState tictactoe::GameLogic::GetState() const
{
	return m_gameState;
}

void tictactoe::GameLogic::SetComputerStrategy(EStrategy strategyType)
{
	switch (strategyType)
	{
	case EStrategy::Easy:
		m_computerStrategy = std::make_shared<EasyStrategy>();
		break;
	case EStrategy::Medium:
		m_computerStrategy = std::make_shared<MediumStrategy>();
		break;
	default:
		break;
	}
}

void tictactoe::GameLogic::SetComputerStrategy(std::shared_ptr<IStrategy> newStrategy)
{
	m_computerStrategy = newStrategy;
}

void tictactoe::GameLogic::Reset()
{
	for (int index1 = 0; index1 < GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < GetBoardSize(); ++index2)
			m_gameBoard.SetElementAt('-', index1, index2);
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
