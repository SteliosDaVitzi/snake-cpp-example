#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>

class Color;
class Rect;

class Renderer
{
public:
	int ShowWindow();
	void Render(Rect* rect, Color* color);
	void HandleInput();
	void Destroy();
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};