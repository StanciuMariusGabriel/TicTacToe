#pragma once
#include "Board.h"
#include "EasyStrategy.h";
#include "MediumStrategy.h"
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
		void MakeComputerMove();
		EGameState GetState() const;

		void SetStrategy(EStrategy strategyType) override;
		void SetStrategy(std::shared_ptr<IStrategy> newStrategy) override;

		void Reset();

	private:
		std::shared_ptr<IStrategy> m_computerStrategy;
		Board m_gameBoard;
		int m_activePlayer;
		EGameState m_gameState;
		int m_combo;

		void UpdateState(int index1, int index2, int m_combo);
		bool IsPositionFilled(int index1, int index2) const;
		bool IsBoardFull() const;
	};
}