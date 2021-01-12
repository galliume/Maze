#include <iostream>
#include "Grid.h"
#include "BinaryTree.h"
#include "Sidewinder.h"


int main(int argc, char** argv)
{
	std::srand(time(0));

	Grid grid(4, 4);
	BinaryTree bTree(grid);

	std::cout << "BinaryTree" << std::endl;
	std::cout << bTree.GetGrid() << std::endl;

	Grid grid2(4, 4);
	Sidewinder sWinder(grid);
	std::cout << "Sidewinder" << std::endl;
	std::cout << sWinder.GetGrid() << std::endl;
	sWinder.GetGrid().ToPng();

	return 0;
}