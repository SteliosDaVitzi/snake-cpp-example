#pragma once
#include <SDL_events.h>

class Color;
class Rect;

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();
	virtual int ShowWindow();
	virtual void RenderObject(Rect* rect, Color* color);
	virtual bool Render();
	virtual void HandleInput(const SDL_Event& event);
	int screenWidth;
	int screenHeight;
};