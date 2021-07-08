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
			if ((player == 1 && gameBoard.GetElementAt(index1, index2) == '0') || (player == 2 && gameBoard.GetElementAt(index1, index2) == 'X'))
			{
				GetPositions(gameBoard, dangerousPositions, combo, index1, index2);
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

void MediumStrategy::GetPositions(const Board& gameBoard, std::vector<std::pair<int, int>> &dangerousPositions, int combo, int index1, int index2)
{
	int current_combo = 0, row_index = index1, col_index = index2, dir = 0;

	while (dir != 8)
	{
		if (row_index >= 0 && row_index < gameBoard.GetBoardSize() && col_index >= 0 && col_index < gameBoard.GetBoardSize())
		{
			if (gameBoard.GetElementAt(row_index, col_index) == gameBoard.GetElementAt(index1, index2))
				++current_combo;
			else
			{
				++dir;
				if (dir % 2 == 0)
				{
					if (current_combo == combo - 1)
					{
						switch (dir)
						{
						case 2:
							if (gameBoard.GetElementAt(row_index, col_index) == '-')
								dangerousPositions.push_back(std::make_pair(row_index, col_index));
							if (row_index + combo < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index + combo, col_index) == '-')
								dangerousPositions.push_back(std::make_pair(row_index + combo, col_index));
							break;
						case 4:
							if (gameBoard.GetElementAt(row_index, col_index) == '-')
								dangerousPositions.push_back(std::make_pair(row_index, col_index));
							if (col_index - combo >= 0 && gameBoard.GetElementAt(row_index, col_index - combo) == '-')
								dangerousPositions.push_back(std::make_pair(row_index, col_index - combo));
							break;
						case 6:
							if (gameBoard.GetElementAt(row_index, col_index) == '-')
								dangerousPositions.push_back(std::make_pair(row_index, col_index));
							if (col_index - combo >= 0 && row_index - combo >= 0 && gameBoard.GetElementAt(row_index - combo, col_index - combo) == '-')
								dangerousPositions.push_back(std::make_pair(row_index - combo, col_index - combo));
							break;
						case 8:
							if (gameBoard.GetElementAt(row_index, col_index) == '-')
								dangerousPositions.push_back(std::make_pair(row_index, col_index));
							if (col_index - combo >= 0 && row_index + combo < gameBoard.GetBoardSize()
								&& gameBoard.GetElementAt(row_index + combo, col_index - combo) == '-')
								dangerousPositions.push_back(std::make_pair(row_index + combo, col_index - combo));
							break;
						default:
							break;
						}
						current_combo = 1;
					}

					else
						current_combo = 1;
				}
				row_index = index1;
				col_index = index2;

			}
		}

		else
		{
			++dir;
			if (dir % 2 == 0)
			{
				if (current_combo == combo - 1)
				{
					switch (dir)
					{
					case 2:
						if (row_index + combo < gameBoard.GetBoardSize() && gameBoard.GetElementAt(row_index + combo, col_index) == '-')
							dangerousPositions.push_back(std::make_pair(row_index + combo, col_index));
						break;
					case 4:
						if (col_index - combo >= 0 && gameBoard.GetElementAt(row_index, col_index - combo) == '-')
							dangerousPositions.push_back(std::make_pair(row_index + combo, col_index));
						break;
					case 6:
						if (col_index - combo >= 0 && row_index - combo >= 0 && gameBoard.GetElementAt(row_index - combo, col_index - combo) == '-')
							dangerousPositions.push_back(std::make_pair(row_index - combo, col_index - combo));
						break;
					case 8:
						if (col_index - combo >= 0 && row_index + combo < gameBoard.GetBoardSize()
							&& gameBoard.GetElementAt(row_index + combo, col_index - combo) == '-')
							dangerousPositions.push_back(std::make_pair(row_index + combo, col_index - combo));
						break;
					default:
						break;
					}
					current_combo = 1;
				}
				else
					current_combo = 1;
				row_index = index1;
				col_index = index2;
			}
		}
		switch (dir)
		{
		case 0:
			++row_index;
			break;
		case 1:
			--row_index;
			break;
		case 2:
			--col_index;
			break;
		case 3:
			++col_index;
			break;
		case 4:
			--row_index;
			--col_index;
			break;
		case 5:
			++col_index;
			++row_index;
			break;
		case 6:
			--col_index;
			++row_index;
			break;
		case 7:
			++col_index;
			--row_index;
			break;
		default:
			break;
		}
	}
}

