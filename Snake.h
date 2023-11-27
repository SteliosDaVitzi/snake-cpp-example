#pragma once
#include <list>
#include "SnakeSegment.h"
using namespace std;

enum MoveDirection
{
	Up,
	Down,
	Left,
	Right
};

class Snake
{
public:
	Snake(int& initialSegments, MoveDirection& initialDirection);
	~Snake();
private:
	list<SnakeSegment*> snakeSegments_;
	void SetupSnake(int& initialSegments, MoveDirection& initialDirection);
};