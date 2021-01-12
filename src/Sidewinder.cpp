#include "Sidewinder.h"

Sidewinder::Sidewinder(Grid grid) : grid(grid)
{
	for (int i = GetGrid().GetRow() - 1; i >= 0; i--)
	{
		std::vector<Cell>run = { };

		for (int j = GetGrid().GetColumn() - 1; j >= 0; j--)
		{
			Cell* cell = &GetGrid().GetCells()[i][j];
			run.push_back(*cell);

			bool atEasternBoundary = (nullptr == cell->east);
			bool atNorthernBoundary = (nullptr == cell->north);
			bool shouldCloseOut = atEasternBoundary || (!atNorthernBoundary && std::rand() % 2 == 0);

			if (shouldCloseOut)
			{
				int index = std::rand() % run.size();
				Cell* member = &GetGrid().GetCells()[run[index].GetRow()][run[index].GetColumn()];
				if (nullptr != member->north)
				{
					GetGrid().GetCells()[run[index].GetRow()][run[index].GetColumn()].Link(
						&GetGrid().GetCells()[member->north->GetRow()][member->north->GetColumn()]
					);
				}

				run.clear();
			}
			else
			{
				cell->Link(cell->east);
			}
		}
	}
}
