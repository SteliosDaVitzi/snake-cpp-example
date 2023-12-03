#include "Snake.h"
#include <iostream>

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

	cout << "Initial cell row : " << initialCell->GetRow() << ", and column : " << initialCell->GetColumn() << endl;

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
	snakeSegments_.push_back(segment);

	grid_->GetCellByCoordinates(row, column)->SetSnakeSegment(segment);
}

void Snake::Render()
{
	for (SnakeSegment* segment : snakeSegments_)
		segment->Render();
}

void Snake::Move()
{
	cout << "Snake moved." << endl;

	for (auto it = snakeSegments_.begin(); it != snakeSegments_.end(); ++it) {
		auto currentElement = *it;

		if(it == snakeSegments_.begin())
		{
			cout << "Head!" << endl;
			currentElement->UpdatePosition(true, currentDirection_, nullptr);
		}
		else if(next(it) != snakeSegments_.end())
		{
			cout << "Body part!" << endl;
			auto nextElement = *next(it);
			currentElement->UpdatePosition(false, currentDirection_, nextElement);
		}

		/*if (next(it) != snakeSegments_.end()) {
			auto nextElement = *next(it);
			currentElement->UpdatePosition(false, currentDirection_, nextElement);
		}
		else 
		{
			currentElement->UpdatePosition(true, currentDirection_, nullptr);
		}*/
	}
}

void Snake::ChangeDirection(MoveDirection newDirection)
{
	if (newDirection == currentDirection_ 
		|| (currentDirection_ == Up && newDirection == Down)
		|| (currentDirection_ == Down && newDirection == Up)
		|| (currentDirection_ == Left && newDirection == Right)
		|| (currentDirection_ == Right && newDirection == Left))
		return;

	currentDirection_ = newDirection;
}

