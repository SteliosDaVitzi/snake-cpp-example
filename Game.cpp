#include "Game.h"
#include "Grid.h"
#include "Snake.h"
#include <thread>
#include <chrono>
#include "Renderer.h"

Game::Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer)
{
    renderer_ = renderer;
	grid_ = new Grid(rows, columns, renderer);
	snake_ = new Snake(initialSnakeSegments, initialDirection, grid_, renderer);
}

Game::~Game()
{
    delete grid_;
    delete snake_;

    grid_ = nullptr;
    snake_ = nullptr;
}

void Game::Run()
{
	Render();
	
    this_thread::sleep_for(chrono::milliseconds(step_));

    KeyCode input = renderer_->Input();
    MoveDirection dir;

    switch (input)
    {
    case ArrowUp:
        dir = Up;
        break;
    case ArrowDown:
        dir = Down;
        break;
    case ArrowLeft:
        dir = Left;
        break;
    case ArrowRight:
        dir = Right;
        break;
    }

    snake_->ChangeDirection(dir);

    snake_->Move();
}

void Game::Render()
{
	grid_->Render();
	snake_->Render();
}
