#include "DistanceGrid.h"

std::string DistanceGrid::ContentsOf(Cell* cell)
{
	if (distances->Exists(cell))
	{
		return std::to_string(distances->GetDistance(cell));
	}
	else
	{
		return Grid::ContentsOf(cell);
	}
}

std::ostream& operator<<(std::ostream& os, DistanceGrid grid)
{
	std::string output = "+";
	for (int i = 0; i < grid.GetColumn(); i++) output += "---+";
	output += "\n";

	for (int i = 0; i < grid.GetRow(); i++)
	{
		std::string top = "|";
		std::string bottom = "+";

		for (int j = 0; j < grid.GetColumn(); j++)
		{
			Cell cell = grid.GetCells()[i][j];
			std::string body = " " + grid.ContentsOf(&cell) + " ";
			std::string eastBoundary = (nullptr != cell.east && cell.IsLinked(cell.east)) ? " " : "|";
			top += body + eastBoundary;

			std::string southBoundary = (nullptr != cell.south && cell.IsLinked(cell.south)) ? "   " : "---";
			std::string corner = "+";
			bottom += southBoundary + corner;
		}

		output += top + "\n";
		output += bottom + "\n";
	}

	os << output;

	return os;
}
