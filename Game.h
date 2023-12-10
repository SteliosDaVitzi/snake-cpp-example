#pragma once
#include "IConsumablesGenerator.h"
#include "Snake.h"

enum GameState
{
	NotStarted,
	InProgress
};

class Game
{
public:
	Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer, IConsumablesGenerator* consumablesGenerator, OnSnakeEatsItself onSnakeEatsItself);
	~Game();
	void Run();
	void SetStep(float step);
private:
	Renderer* renderer_;
	long step_ = 100;
	Grid* grid_;
	Snake* snake_;
	void Render();
};