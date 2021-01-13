#include <iostream>
#include "Magick++.h"

#include "Grid.h"
#include "BinaryTree.h"
#include "Sidewinder.h"
#include "DistanceGrid.h"

int main(int argc, char** argv)
{
	Magick::InitializeMagick(*argv);
	std::srand(time(0));

	Grid grid(10, 10);
	BinaryTree bTree(grid);
	grid.ToPng("BinaryTree.png");

	std::cout << "BinaryTree" << std::endl;
	std::cout << grid << std::endl;

	Grid grid2(10, 10);
	Sidewinder sWinder(grid2);
	grid2.ToPng("Sidewinder.png");

	std::cout << "Sidewinder" << std::endl;
	std::cout << grid2 << std::endl;

	DistanceGrid dGrid(4, 4);
	BinaryTree bTreeDGrid(dGrid);
	Distances dist(dGrid.GetCells()[0][0]);
	dGrid.SetDistances(&dist);
	dGrid.ToPng("DistanceGrid.png");

	std::cout << " DistancesGrid" << std::endl;
	std::cout << dGrid << std::endl;

	return 0;
}