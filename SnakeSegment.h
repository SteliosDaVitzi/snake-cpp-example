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
	void UpdatePosition(bool isHead, MoveDirection moveDirection, SnakeSegment* nextSegment);
	int PreviousRow();
	int PreviousColumn();
	int CurrentRow();
	int CurrentColumn();
	void Render();
	Rect rect;
	Color color;
	int index = 0;
private:
	Grid* grid_;
	Renderer* renderer_;
	int currentRow_, currentColumn_;
	int previousRow_, previousColumn_;
	void UpdateGridSnakeSegment();
};
