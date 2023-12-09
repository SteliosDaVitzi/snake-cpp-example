#pragma once
#include "IConsumablesGenerator.h"
#include "Snake.h"

enum GameState
{
	NotStarted,
	InProgress
};

//typedef void(*OnSnakeEatsItself);

class Game
{
public:
	Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer, IConsumablesGenerator* consumablesGenerator);
	~Game();
	void Run();
private:
	Renderer* renderer_;
	const long step_ = 200;
	int counter_;
	Grid* grid_;
	Snake* snake_;
	void Render();
};