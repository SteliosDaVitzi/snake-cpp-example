#pragma once
#include "Snake.h"

enum GameState
{
	NotStarted,
	InProgress
};

class Game
{
public:
	Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer);
	~Game();
	void Run();
	Grid* GetGrid();
	Snake* GetSnake();
private:
	const float step_ = 0.5f;
	int counter_;
	Grid* grid_;
	Snake* snake_;
	void ClearGame();
	void Render();
};