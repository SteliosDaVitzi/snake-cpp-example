#include <SDL.h>
#include "SDLRenderer.h"
#include "VisualComponents.h"
#include <iostream>
using namespace std;

class Rect;
class Color;

SDL_Event event;

SDLRenderer::SDLRenderer(int screenWidth, int screenHeight)
{
    screen_width = screenWidth;
    screen_height = screenHeight;
}

SDLRenderer::~SDLRenderer()
{
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
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
                cout << "Escape!!!" << endl;
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

    window_ = SDL_CreateWindow("Classic Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    if (!window_) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return 1;
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer_) {
        SDL_Log("Renderer creation failed: %s", SDL_GetError());
        return 1;
    }

    return 0;
}

void SDLRenderer::RenderObject(Rect* rect, Color* color)
{
	SDL_SetRenderDrawColor(renderer_, color->r, color->g, color->b, color->a);

	const SDL_Rect sdlRect = { (int)rect->position.X , (int)rect->position.Y , 10, 10 };

	SDL_RenderFillRect(renderer_, &sdlRect);
	SDL_RenderPresent(renderer_);
}