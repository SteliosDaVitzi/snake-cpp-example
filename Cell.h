#pragma once
#include "IConsumable.h"
#include "SnakeSegment.h"
#include "VisualComponents.h"
class Rect;
class Color;

class Cell
{
public:
	Cell(int row, int column);
	int GetRow();
	int GetColumn();
	void SetSnakeSegment(SnakeSegment* segment);
	SnakeSegment* GetSnakeSegment();
	void SetConsumable(IConsumable* consumable);
	IConsumable* GetConsumable();
	Color color;
	Rect rect;
private:
	int row_;
	int column_;
	SnakeSegment* snakeSegment_ = nullptr;
	IConsumable* consumable_ = nullptr;
};
