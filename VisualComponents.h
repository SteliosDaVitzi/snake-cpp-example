#pragma once

struct Vector2
{
public:
	float X;
	float Y;
	Vector2(float x, float y) :X(x), Y(y){}
};

class Rect
{
public:
	Vector2 position;
	Rect() : position(Vector2(0, 0)){}
};

class Color
{
public:
	float r;
	float g;
	float b;
	float a;
};