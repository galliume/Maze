#include "BinaryTree.h"
#include <ctime>

BinaryTree::BinaryTree(Grid grid) : grid(grid)
{
	for (int i = 0; i < GetGrid().GetRow(); i++)
	{
		for (int j = 0; j < GetGrid().GetColumn(); j++)
		{
			std::vector<Cell>neighbors = { };

			if (nullptr != GetGrid().GetCells()[i][j].north)
			{
				neighbors.push_back(*GetGrid().GetCells()[i][j].north);
			}
			if (nullptr != GetGrid().GetCells()[i][j].east)
			{
				neighbors.push_back(*GetGrid().GetCells()[i][j].east);
			}

			if (neighbors.size())
			{
				int index = std::rand() % neighbors.size();
				GetGrid().GetCells()[i][j].Link(&GetGrid().GetCells()[neighbors[index].GetRow()][neighbors[index].GetColumn()]);
			}
		}
	}
}