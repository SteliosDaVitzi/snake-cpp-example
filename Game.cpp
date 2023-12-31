#include "Game.h"
#include "Grid.h"
#include "Snake.h"
#include <thread>
#include <chrono>
#include "Renderer.h"
#include "Utils.h"
using namespace this_thread;
using namespace chrono;

Game::Game(int& rows, int& columns, int& initialSnakeSegments, MoveDirection& initialDirection, Renderer* renderer, IConsumablesGenerator* consumablesGenerator, OnSnakeEatsItself onSnakeEatsItself)
{
    renderer_ = renderer;
	grid_ = new Grid(rows, columns, renderer, consumablesGenerator);
	snake_ = new Snake(initialSnakeSegments, initialDirection, grid_, &step_,  renderer, onSnakeEatsItself);
}

Game::~Game()
{
    delete grid_;
    delete snake_;
}

void Game::Run()
{
	Render();

    Utils::Debug("Step : ", step_);

    sleep_for(milliseconds(step_));

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
