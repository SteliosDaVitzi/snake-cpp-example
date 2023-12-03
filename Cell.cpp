#include "Cell.h"

Cell::Cell(const int row, const int column)
{
	row_ = row;
	column_ = column;
}

void Cell::SetSnakeSegment(SnakeSegment* segment)
{
	snakeSegment_ = segment;
}


int Cell::GetRow()
{
	return row_;
}

int Cell::GetColumn()
{
	return column_;
}


