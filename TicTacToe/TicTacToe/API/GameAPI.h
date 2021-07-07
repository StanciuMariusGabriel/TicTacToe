#pragma once
#include <memory>

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

	class IGame
	{
	public:
		using Game = std::shared_ptr<IGame>;

		virtual ~IGame() = default;

		virtual int GetBoardSize() const = 0;
		virtual char GetElementAt(int index1, int index2) const = 0;
		virtual int GetActivePlayer() const = 0;

		virtual EMoveResult MakeMove(int index1, int index2) = 0;
		virtual EGameState GetState() const = 0;

		static IGame::Game Produce(int dim, int combo);
	};
}
