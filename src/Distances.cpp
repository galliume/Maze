#include "Distances.h"

Distances::Distances(Cell root)
{
	cells.emplace(&root, 0);
	InitDistances(&root);
}

bool Distances::Exists(Cell* cell)
{
	for (auto search : cells)
	{
		if (cell->GetUuid() == std::get<0>(search)->GetUuid()) return true;
	}
	return false;
}

void Distances::InitDistances(Cell* root)
{
	std::vector<Cell*> frontier = { root };
	std::vector<Cell*> newFrontier = { };

	while (frontier.size())
	{
		newFrontier.clear();

		for (auto cell : frontier)
		{
			for (auto link : cell->GetLinks())
			{
				if (!Exists(link))
				{
					SetDistance(link, GetDistance(cell) + 1);
					newFrontier.push_back(link);
				}
			}
		}

		frontier.clear();
		copy(newFrontier.begin(), newFrontier.end(), back_inserter(frontier));
	}
}

int Distances::GetDistance(Cell* cell)
{
	for (auto search : cells)
	{
		if (cell->GetUuid() == std::get<0>(search)->GetUuid()) return std::get<1>(search);
	}
}

void Distances::SetDistance(Cell* cell, int distance)
{
	cells.insert({ cell, distance });
}