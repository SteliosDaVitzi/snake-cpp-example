#include "Game.h"
#include "Grid.h"
#include "Snake.h"
#include <windows.h>
#include "Renderer.h"

Game::Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer)
{
	ClearGame();

	grid_ = new Grid(rows, columns, renderer);
	snake_ = new Snake(initialSnakeSegments, initialDirection, grid_, renderer);
}

Game::~Game()
{
	ClearGame();
}

Grid* Game::GetGrid()
{
	return grid_;
}


void Game::ClearGame()
{
	delete grid_;
	delete snake_;

	grid_ = nullptr;
	snake_ = nullptr;
}

void Game::Run()
{
	snake_->Move();
	Sleep(step_ * 1000);
}

void Game::Render()
{
	grid_->Render();
	snake_->Render();
}
