#pragma once
#include "GameLogic.h"
#include "API/GameAPI.h"

class MediumStrategy : public tictactoe::IStrategy
{
public:
	std::pair<int, int> ComputerMove(const Board& gameBoard, int player, int combo);

private:
	void GetPositions(const Board& gameBoard, std::vector<std::pair<int, int>> &dangerousPositions, int combo, int index1, int index2);
};
