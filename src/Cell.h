#pragma once
#include <iostream>
#include <vector>

class Cell
{
public:
	Cell(int uuid, int row, int column);
	void Link(Cell* cell, bool bidi = true);
	void Unlink(Cell* cell, bool bidi = true);
	std::vector<Cell*>& GetLinks() { return links; };
	bool IsLinked(Cell* cell);
	std::vector<Cell>& Neighbors();
	Cell* north = nullptr;
	Cell* south = nullptr;
	Cell* east = nullptr;
	Cell* west = nullptr;
	int GetRow() { return row; };
	int GetColumn() { return column; };
	int GetUuid() { return uuid; };
	friend bool operator==(const Cell& lhs, const Cell& rhs);
private:
	int uuid;
	int row;
	int column;
	std::vector<Cell*> links = {};
};