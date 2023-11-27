#include "Snake.h"

Snake::Snake(int& initialSegments, MoveDirection& initialDirection)
{
	SetupSnake(initialSegments, initialDirection);
}

Snake::~Snake()
{
	for (const SnakeSegment* segment : snakeSegments_)
	{
		delete segment;
		segment = nullptr;
	}
}

void Snake::SetupSnake(int& initialSegments, MoveDirection& initialDirection)
{
	for(int i =0;i < initialSegments;i++)
	{
		int tempRow = 2;
		int tempColumn = 3;
		SnakeSegment* segment = new SnakeSegment(tempRow, tempColumn);
		snakeSegments_.push_back(segment);
	}
}
