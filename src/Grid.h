#pragma once

#include <vector>
#include <unordered_map>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Magick++.h"

#include "Cell.h"

class Grid
{
public:
	Grid(int row, int column);
	void PrepareGrid();
	void ConfigureCell();
	Cell* RandomCell();
	int GetSize() { return row * column; };
	int GetRow() { return row; };
	int GetColumn() { return column; };
	std::unordered_map<int, std::vector<Cell>>& GetCells() { return cells; };
	friend std::ostream& operator<<(std::ostream& os, Grid grid);
	void ToPng(std::string filename, int cellSize = 10);
private:
	int row = 0;
	int column = 0;
	std::unordered_map<int, std::vector<Cell>> cells;
};