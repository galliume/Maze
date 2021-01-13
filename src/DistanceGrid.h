#pragma once

#include <iomanip>

#include "Grid.h"
#include "Distances.h"

class DistanceGrid : public Grid
{
public :
	DistanceGrid(int row, int column) : Grid(row, column) {};
	void SetDistances(Distances* d) { distances = d; };
	virtual std::string ContentsOf(Cell* cell) override;
	friend std::ostream& operator<<(std::ostream& os, DistanceGrid grid);
private:
	Distances* distances = nullptr;
};