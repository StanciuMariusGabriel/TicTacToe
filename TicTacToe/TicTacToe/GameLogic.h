#pragma once
#include "Board.h"
#include "API/GameAPI.h"

namespace tictactoe
{
	class GameLogic : public IGame
	{
	public:
		GameLogic(int dim, int combo);

		int GetBoardSize() const;
		char GetElementAt(int index1, int index2) const;
		int GetActivePlayer() const;

		EMoveResult MakeMove(int index1, int index2);
		EGameState GetState() const;

	private:
		Board m_gameBoard;
		int m_activePlayer;
		EGameState m_gameState;
		int m_combo;

		void UpdateState(int index1, int index2, int m_combo);
		bool IsPositionFilled(int index1, int index2) const;
		bool IsBoardFull() const;
	};
}