#include "EasyStrategy.h"
#include <vector>
#include <random>

std::pair<int, int> EasyStrategy::ComputerMove(const Board &gameBoard, int player, int combo)
{
	std::pair<int, int> indexes(-1, -1);
	std::vector<std::pair<int, int>> moveChoices;

	std::random_device rd;
	std::mt19937 gen(rd());

	for (int index1 = 0; index1 < gameBoard.GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < gameBoard.GetBoardSize(); ++index2)
			if (gameBoard.GetElementAt(index1, index2) == '-')
				moveChoices.push_back(std::make_pair(index1, index2));

	std::uniform_int_distribution<> random(0, moveChoices.size()-1);

	return moveChoices[random(gen)];
}
