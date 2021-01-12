#pragma once
#include "Grid.h"

class BinaryTree
{
public:
	BinaryTree(Grid grid);
	Grid& GetGrid() { return grid; };
private:
	Grid grid;
};