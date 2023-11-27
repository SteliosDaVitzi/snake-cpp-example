#include "SnakeSegment.h"

SnakeSegment::SnakeSegment(int& row, int& column)
{
	currentRow_ = row;
	currentColumn_ = column;

	previousRow_ = currentRow_;
	previousColumn_ = currentColumn_;
}
