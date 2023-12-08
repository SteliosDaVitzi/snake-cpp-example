#pragma once

class Color;
class Rect;

enum KeyCode
{
	None,
	ArrowUp,
	ArrowDown,
	ArrowLeft,
	ArrowRight
};

class Renderer
{
public:
	Renderer() = default;
	virtual ~Renderer() = default;
	virtual int ShowWindow();
	virtual void RenderObject(Rect* rect, Color* color);
	virtual bool Render();
	virtual KeyCode Input();
	int screenWidth;
	int screenHeight;
};