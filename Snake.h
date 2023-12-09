#pragma once
#include <list>
#include "ISnakeEffects.h"
#include "Game.h";
class SnakeSegment;
class Renderer;
class Grid;
using namespace std;

enum MoveDirection
{
	Up,
	Down,
	Left,
	Right
};

class Snake: public ISnakeEffects
{
	

public:
	Snake(int& initialSegments, MoveDirection& initialDirection, Grid* grid, Renderer* renderer);
	~Snake();
	void Move();
	void ChangeDirection(MoveDirection& newDirection);
	void Render();
	void increaseSize() override;
	void increaseSpeed() override;
private:
	Grid* grid_;
	Renderer* renderer_;
	list<SnakeSegment*> snakeSegments_;
	MoveDirection currentDirection_;
	void SetupSnake(const int& initialSegments, MoveDirection& initialDirection);
	void AddSegment(const int& row, const int& column);
};