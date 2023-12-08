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
private:
	Renderer* renderer_;
	const long step_ = 200;
	int counter_;
	Grid* grid_;
	Snake* snake_;
	void ClearGame();
	void Render();
};