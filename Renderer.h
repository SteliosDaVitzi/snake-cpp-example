#pragma once

class Color;
class Rect;

enum KeyCode
{
	None,
	ArrowUp,
	ArrowDown,
	ArrowLeft,
	ArrowRight,
	Escape
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
	int screen_width;
	int screen_height;
};