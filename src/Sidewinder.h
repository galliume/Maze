#pragma once
#include "Grid.h"

class Sidewinder
{
public:
	Sidewinder(Grid grid);
	Grid& GetGrid() { return grid; };
private:
	Grid grid;
};