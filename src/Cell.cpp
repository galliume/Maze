#include "Cell.h"

Cell::Cell(int uuid, int row, int column) : uuid(uuid), row(row), column(column)
{

}

void Cell::Link(Cell* cell, bool bidi)
{
	links.push_back(*cell);
	if (bidi) cell->Link(this, false);
}

void Cell::Unlink(Cell* cell, bool bidi)
{
	links.erase(find(links.begin(), links.end(), *cell));
	if (bidi) cell->Unlink(this, false);
}

bool Cell::IsLinked(Cell cell)
{
	return (std::end(links) != find(links.begin(), links.end(), cell));
}

std::vector<Cell>& Cell::Neighbors()
{
	std::vector<Cell> list;

	if (north) list.push_back(*north);
	if (south) list.push_back(*south);
	if (east) list.push_back(*east);
	if (west) list.push_back(*west);

	return list;
}

bool operator==(const Cell& lhs, const Cell& rhs)
{
	return lhs.uuid == rhs.uuid;
}