#include "Cell.h"

Cell::Cell(const int row, const int column):row_(row), column_(column), color({}), rect({}){}

SnakeSegment* Cell::GetSnakeSegment()
{
	return snakeSegment_;
}

void Cell::SetSnakeSegment(SnakeSegment* segment)
{
	snakeSegment_ = segment;
}

IConsumable* Cell::GetConsumable()
{
	return consumable_;
}

void Cell::SetConsumable(IConsumable* consumable)
{
	consumable_ = consumable;
}


int Cell::GetRow()
{
	return row_;
}

int Cell::GetColumn()
{
	return column_;
}