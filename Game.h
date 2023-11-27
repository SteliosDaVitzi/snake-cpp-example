#pragma once
#include "Grid.h"
#include "Snake.h"


class Game
{
public:
	Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection);
	~Game();
private:
	Grid* grid_;
	Snake* snake_;
	void ClearGame();
};