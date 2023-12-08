#pragma once
#include "Snake.h"
#include "VisualComponents.h"

class Color;
class Rect;
class Grid;
class Renderer;

class SnakeSegment
{
public:
	SnakeSegment(int row, int column, Renderer* renderer, Grid* grid, int index);
	~SnakeSegment();
	void UpdatePosition(bool isHead, MoveDirection moveDirection, SnakeSegment* nextSegment);
	int PreviousRow();
	int PreviousColumn();
	void Render();
	Rect rect;
	Color color;
	int index;
private:
	Grid* grid_;
	Renderer* renderer_;
	int currentRow_, currentColumn_;
	int previousRow_, previousColumn_;
	void UpdateGridSnakeSegment();
};
