#include <iostream>
#include "Grid.h"
#include "BinaryTree.h"
#include "Sidewinder.h"

#include "Magick++.h"

int main(int argc, char** argv)
{
	Magick::InitializeMagick(*argv);
	std::srand(time(0));

	Grid grid(10, 10);
	BinaryTree bTree(grid);
	bTree.GetGrid().ToPng("BinaryTree.png");

	std::cout << "BinaryTree" << std::endl;
	std::cout << bTree.GetGrid() << std::endl;

	Grid grid2(10, 10);
	Sidewinder sWinder(grid);
	std::cout << "Sidewinder" << std::endl;
	std::cout << sWinder.GetGrid() << std::endl;
	sWinder.GetGrid().ToPng("Sidewinder.png");

	return 0;
}