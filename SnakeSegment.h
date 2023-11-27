#pragma once
class SnakeSegment
{
public:
	SnakeSegment(int& row, int& column);
private:
	int currentRow_, currentColumn_;
	int previousRow_, previousColumn_;
};