#pragma once
#include "API/GameAPI.h"
#include "GameLogic.h"

class EasyStrategy : public tictactoe::IStrategy
{
public:
	std::pair<int, int> ComputerMove(const Board &gameBoard, int player, int combo);
};
