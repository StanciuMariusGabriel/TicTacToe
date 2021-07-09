#include "MediumStrategy.h"
#include <vector>
#include <random>

std::pair<int, int> MediumStrategy::ComputerMove(const Board& gameBoard, int player, int combo)
{
	std::pair<int, int> indexes(-1, -1);
	std::vector<std::pair<int, int>> dangerousPositions;

	for (int index1 = 0; index1 < gameBoard.GetBoardSize(); ++index1)
		for (int index2 = 0; index2 < gameBoard.GetBoardSize(); ++index2)
		{
			if (gameBoard.GetElementAt(index1, index2) == '-')
			{
				if(player == 1)
					GetPositions(gameBoard, dangerousPositions, combo, '0', index1, index2);
				else
					GetPositions(gameBoard, dangerousPositions, combo, 'X', index1, index2);
			}
		}
	if (dangerousPositions.size() != 0)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> random(0, dangerousPositions.size() - 1);
		return dangerousPositions[random(gen)];
	}
	else
	{
		std::vector<std::pair<int, int>> moveChoices;

		std::random_device rd;
		std::mt19937 gen(rd());

		for (int index1 = 0; index1 < gameBoard.GetBoardSize(); ++index1)
			for (int index2 = 0; index2 < gameBoard.GetBoardSize(); ++index2)
				if (gameBoard.GetElementAt(index1, index2) == '-')
					moveChoices.push_back(std::make_pair(index1, index2));

		std::uniform_int_distribution<> random(0, moveChoices.size() - 1);

		return moveChoices[random(gen)];
	}
}

void MediumStrategy::GetPositions(const Board& gameBoard, std::vector<std::pair<int, int>> &dangerousPositions, int combo, char symbol, int index1, int index2)
{
	int current_combo, row_index = index1, col_index = index2, dir = 0;

	while (dir != 8)
	{
		current_combo = 0;
		bool found = false;
		switch (dir)
		{
		case 0:
			++row_index;
			while (row_index < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				++row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 1:
			--row_index;
			while (row_index >= 0 && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				--row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 2:
			--col_index;
			while (col_index >= 0 && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				--col_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 3:
			++col_index;
			while (col_index < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				++col_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 4:
			--row_index;
			--col_index;
			while (col_index >= 0 && row_index>=0 && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				--col_index;
				--row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 5:
			++col_index;
			++row_index;
			while (col_index < gameBoard.GetBoardSize() && row_index < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				++col_index;
				++row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 6:
			--col_index;
			++row_index;
			while (col_index >= 0 && row_index < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				--col_index;
				++row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		case 7:
			++col_index;
			--row_index;
			while (col_index < gameBoard.GetBoardSize() && row_index >=0 && gameBoard.GetElementAt(row_index, col_index) == symbol)
			{
				++current_combo;
				++col_index;
				--row_index;
			}
			if (current_combo == combo - 1)
			{
				dangerousPositions.push_back(std::make_pair(index1, index2));
				found = true;
			}
			row_index = index1;
			col_index = index2;
			break;
		default:
			break;
		}
		if (found)
			break;
		++dir;
	}
}

