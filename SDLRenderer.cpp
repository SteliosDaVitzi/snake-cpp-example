#include <SDL.h>
#include "SDLRenderer.h"
#include "VisualComponents.h"
#include <iostream>
using namespace std;

class Rect;
class Color;

SDL_Event event;

SDLRenderer::SDLRenderer(int screen_width, int screen_height)
{
    screenWidth = screen_width;
    screenHeight = screen_height;
}

SDLRenderer::~SDLRenderer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool SDLRenderer::Render()
{
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            return false;
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                return false;
            }
        }
    }

    return true;
}

KeyCode SDLRenderer::Input()
{
    while (SDL_PollEvent(&event)) {
    	if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                return ArrowUp;
            case SDLK_DOWN:
                return ArrowDown;
            case SDLK_LEFT:
                return ArrowLeft;
            case SDLK_RIGHT:
                return ArrowRight;
            default:
                return None;
            }
        }
    }
    
}


int SDLRenderer::ShowWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Classic Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return 1;
    }

    return 0;
}

void SDLRenderer::RenderObject(Rect* rect, Color* color)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);

	const SDL_Rect sdlRect = { (int)rect->position.X , (int)rect->position.Y , 10, 10 };

	SDL_RenderFillRect(renderer, &sdlRect);
	SDL_RenderPresent(renderer);
}