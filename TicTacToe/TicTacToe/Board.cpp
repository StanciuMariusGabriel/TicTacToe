#include "Board.h"

Board::Board(int dim)
{
	m_board.resize(dim);
	for (int index1 = 0; index1 < dim; ++index1)
		m_board[index1].resize(dim, '-');
}

char Board::GetElementAt(int index1, int index2) const
{
	return m_board[index1][index2];
}

void Board::SetElementAt(char elem, int index1, int index2)
{
	m_board[index1][index2] = elem;
}

bool Board::CheckPlayerWin(int index1, int index2, int combo)
{
	int current_combo = 0, row_index = index1, col_index = index2, dir = 0;

	while (dir != 8)
	{
		if (row_index >= 0 && row_index < m_board.size() && col_index >= 0 && col_index < m_board.size())
		{
			if (m_board[row_index][col_index] == m_board[index1][index2])
				++current_combo;
			else
			{
				++dir;
				row_index = index1;
				col_index = index2;
				if (dir % 2 == 0)
				{
					if (current_combo >= combo)
						return true;
					else
						current_combo = 1;
				}
			}
		}
		else
		{
			++dir;
			row_index = index1;
			col_index = index2;
			if (dir % 2 == 0)
			{
				if (current_combo >= combo)
					return true;
				else
					current_combo = 1;
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
			return false;
		}
	}
	return false;
}

int Board::GetBoardSize() const
{
	return m_board.size();
}
