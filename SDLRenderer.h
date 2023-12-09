#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Renderer.h"

class SDLRenderer: public Renderer
{
public:
	SDLRenderer(int screenWidth, int screenHeight);
	~SDLRenderer() override;
	int ShowWindow() override;
	void RenderObject(Rect* rect, Color* color) override;
	bool Render() override;
	KeyCode Input() override;
private:
	SDL_Window* window_ = nullptr;
	SDL_Renderer* renderer_ = nullptr;
};
