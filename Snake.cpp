#include "Snake.h"
#include <iostream>
#include <string>

#include "Cell.h"
#include "Grid.h"
#include "SnakeSegment.h"
using namespace std;

Snake::Snake(int& initialSegments, MoveDirection& initialDirection, Grid* grid, Renderer* renderer)
{
	grid_ = grid;
	renderer_ = renderer;
	SetupSnake(initialSegments, initialDirection);
}

Snake::~Snake()
{
	for (const SnakeSegment* segment : snakeSegments_)
	{
		delete segment;
		segment = nullptr;
	}
}

void Snake::SetupSnake(const int& initialSegments, MoveDirection& initialDirection)
{
	const auto initialCell = grid_->GetCenterCell();

	//cout << "Initial cell row : " << initialCell->GetRow() << ", and column : " << initialCell->GetColumn() << endl;

	ChangeDirection(initialDirection);

	for(int i =0;i < initialSegments;i++)
	{
		switch (initialDirection)
		{
		case Up:
			AddSegment(initialCell->GetRow() - i, initialCell->GetColumn());
			break;
		case Down:
			AddSegment(initialCell->GetRow() + i, initialCell->GetColumn());
			break;
		case Left:
			AddSegment(initialCell->GetRow(), initialCell->GetColumn() + i);
			break;
		case Right:
			AddSegment(initialCell->GetRow(), initialCell->GetColumn() - i);
			break;
		}
	}
		
}

void Snake::AddSegment(const int& row, const int& column)
{
	int index = snakeSegments_.size() + 1;
	const auto segment = new SnakeSegment(row, column, renderer_, grid_, index);
	snakeSegments_.emplace_back(segment);

	grid_->GetCellByCoordinates(row, column)->SetSnakeSegment(segment);
}

void Snake::Render()
{
	for (const auto segment : snakeSegments_)
	{
		segment->Render();
	}
		
}

void Snake::Move()
{
	/*MoveDirection dir = renderer_->Input->GetMoveDirection();
	ChangeDirection(dir);*/

	for (auto it = snakeSegments_.begin(); it != snakeSegments_.end(); ++it) {

		const auto currentElement = *it;

		if(it == snakeSegments_.begin())
		{
			currentElement->UpdatePosition(true, currentDirection_, nullptr);
		}
		else
		{
			const auto prevElement = *prev(it);
			currentElement->UpdatePosition(false, currentDirection_, prevElement);
		}
	}
}

void Snake::ChangeDirection(MoveDirection& newDirection)
{
	if (newDirection == currentDirection_)return;

	switch (newDirection)
	{
	case Up:
		if (currentDirection_ == Down) return;
		currentDirection_ = Up;
		break;
	case Down:
		if (currentDirection_ == Up) return;
		currentDirection_ = Down;
		break;
	case Left:
		if (currentDirection_ == Right) return;
		currentDirection_ = Left;
		break;
	case Right:
		if (currentDirection_ == Left) return;
		currentDirection_ = Right;
		break;
	}
}
