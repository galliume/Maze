#include "Grid.h"

Grid::Grid(int row, int column) : row(row), column(column)
{
	PrepareGrid();
	ConfigureCell();
}

void Grid::PrepareGrid()
{
	int index = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			GetCells()[i].push_back(Cell(index, i, j));
			index++;
		}
	}
}

void Grid::ConfigureCell()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			GetCells()[i][j].north = (0 <= i - 1) ? &GetCells()[i - 1][j] : nullptr;
			GetCells()[i][j].south = (row > i + 1) ? &GetCells()[i + 1][j] : nullptr;
			GetCells()[i][j].east = (column > j + 1) ? &GetCells()[i][j + 1] : nullptr;
			GetCells()[i][j].west = (0 <= j - 1) ? &GetCells()[i][j - 1] : nullptr;
		}
	}
}

Cell* Grid::RandomCell()
{
	int randomRow = std::rand() % row;
	int randomColumn = std::rand() % column;

	return &GetCells()[randomRow][randomColumn];
}

std::ostream& operator<<(std::ostream& os, Grid grid)
{
	std::string output = "+";	
	for (int i = 0; i < grid.column; i++) output += "---+";
	output += "\n";

	for (int i = 0; i < grid.row; i++)
	{
		std::string top = "|";
		std::string bottom = "+";

		for (int j = 0; j < grid.column; j++)
		{
			Cell cell = grid.GetCells()[i][j];
			std::string body = "   ";
			std::string eastBoundary = (nullptr != cell.east && cell.IsLinked(*cell.east)) ? " " : "|";
			top += body + eastBoundary;

			std::string southBoundary = (nullptr != cell.south && cell.IsLinked(*cell.south)) ? "   " : "---";
			std::string corner = "+";
			bottom += southBoundary + corner;
		}
		
		output += top + "\n";
		output += bottom + "\n";
	}

	os << output;

	return os;
}

void Grid::ToPng(std::string filename, int cellSize)
{
	int imgWidth = cellSize * column + 1;
	int imgheight = cellSize * row + 1;

	Magick::Image image(Magick::Geometry(imgWidth, imgheight), "white");
	image.strokeColor("black"); 

	for (auto rows : GetCells())
	{
		for (auto cell : rows.second)
		{
			int x1 = cell.GetColumn() * cellSize;
			int y1 = cell.GetRow() * cellSize;
			int x2 = (cell.GetColumn() + 1) * cellSize;
			int y2 = (cell.GetRow() + 1) * cellSize;

			if (nullptr == cell.north)
			{
				image.draw(Magick::DrawableLine(x1, y1, x2, y1));
			}
			if (nullptr == cell.west)
			{
				image.draw(Magick::DrawableLine(x1, y1, x1, y2));
			}

			if (nullptr == cell.east || !cell.IsLinked(*cell.east))
			{
				image.draw(Magick::DrawableLine(x2, y1, x2, y2));
			}
			if (nullptr == cell.south || !cell.IsLinked(*cell.south))
			{
				image.draw(Magick::DrawableLine(x1, y2, x2, y2));
			}
		}
	}

	image.write(filename);
}