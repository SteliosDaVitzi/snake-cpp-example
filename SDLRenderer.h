#pragma once
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Renderer.h"

class SDLRenderer: public Renderer
{
public:
	SDLRenderer(int screen_width, int screen_height);
	~SDLRenderer();
	int ShowWindow() override;
	void RenderObject(Rect* rect, Color* color) override;
	bool Render() override;
	void HandleInput(const SDL_Event& event) override;
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};
