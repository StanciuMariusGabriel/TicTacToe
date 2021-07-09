#pragma once
#include <memory>
#include "Board.h"

namespace tictactoe
{
	enum class EGameState
	{
		Playing,
		Draw,
		Player1Win,
		Player2Win
	};

	enum class EMoveResult
	{
		Success,
		PositionOccupied,
		Invalid
	};

	enum class EStrategy
	{
		Easy,
		Medium
	};

	class IStrategy
	{
	public:
		virtual ~IStrategy() = default;

		virtual std::pair<int, int> ComputerMove(const Board& gameBoard, int player, int combo) = 0;
	};

	class IGame
	{
	public:
		using Game = std::shared_ptr<IGame>;

		virtual ~IGame() = default;

		virtual int GetBoardSize() const = 0;
		virtual char GetElementAt(int index1, int index2) const = 0;
		virtual int GetActivePlayer() const = 0;
		virtual int GetSinglePlayerUserNumber() const = 0;
		virtual bool IsSinglePlayer() const = 0;

		virtual void SetSinglePlayer(int userPlayerNumber) = 0;
		virtual void SetMultiPlayer() = 0;

		virtual EMoveResult MakeMove(int index1, int index2) = 0;
		//virtual void MakeComputerMove() = 0;
		virtual EGameState GetState() const = 0;

		virtual void SetComputerStrategy(EStrategy strategyType) = 0;
		virtual void SetComputerStrategy(std::shared_ptr<IStrategy> newStrategy) = 0;

		virtual void Reset() = 0;

		static IGame::Game Produce(int dim, int combo);
	};
}
