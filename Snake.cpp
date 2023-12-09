#include "Snake.h"
#include <iostream>
#include "Cell.h"
#include "Grid.h"
#include "SnakeSegment.h"
#include "Utils.h"
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
	for (auto it = snakeSegments_.begin(); it != snakeSegments_.end(); ++it) {

		const auto currentElement = *it;

		if(it == snakeSegments_.begin())
		{
			currentElement->UpdatePosition(true, currentDirection_, nullptr);
			const auto currentCell = grid_->GetCellByCoordinates(currentElement->CurrentRow(), currentElement->CurrentColumn());
			if(currentCell != nullptr)
			{
				if (currentCell->GetConsumable() != nullptr)
				{
					currentCell->GetConsumable()->executeConsumableEffect(this);
					currentCell->SetConsumable(nullptr);
					grid_->GenerateConsumableAtRandomCell();
				}

				if(currentCell->GetSnakeSegment() != nullptr)
				{
					if (onSnakeEatsItselfCallback_)
						onSnakeEatsItselfCallback_();
				}
			}
		}
		else
			currentElement->UpdatePosition(false, currentDirection_, *prev(it));
	}
}

void Snake::ChangeDirection(MoveDirection& newDirection)
{
	if (newDirection == currentDirection_) return;

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

void Snake::increaseSize()
{
	Utils::Debug("increased size!");

	auto it = begin(snakeSegments_);
	advance(it, snakeSegments_.size()-1);

	if (it == snakeSegments_.end())
		return;

	SnakeSegment* lastSegment = *it;

	AddSegment(lastSegment->PreviousRow(), lastSegment->PreviousColumn());
}

void Snake::increaseSpeed()
{
	Utils::Debug("increased speed!!");
}