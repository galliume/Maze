#pragma once

#include <unordered_map>

#include "Cell.h"

class Distances
{
public:
	Distances() {};
	Distances(Cell root);
	void InitDistances(Cell* root);
	int GetDistance(Cell* cell);
	bool Exists(Cell* cell);
	std::unordered_map<Cell*, int>& GetCells() { return cells; };
private:
	void SetDistance(Cell* cell, int distance);
	std::unordered_map<Cell*, int> cells;
};