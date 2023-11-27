#include "Game.h"
#include "Grid.h"
#include "Snake.h"

Game::Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection)
{
	ClearGame();

	grid_ = new Grid(rows, columns);
	snake_ = new Snake(initialSnakeSegments, initialDirection);
}

Game::~Game()
{
	ClearGame();
}

void Game::ClearGame()
{
	delete grid_;
	delete snake_;

	grid_ = nullptr;
	snake_ = nullptr;
}

