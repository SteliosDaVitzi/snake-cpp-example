#include "Renderer.h"
//#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>
#include "VisualComponents.h"

void Renderer::Render(Rect* rect, Color* color)
{
    const SDL_Rect sdlRect = { (int)rect->position.X , (int)rect->position.Y , 10, 10};

    SDL_RenderFillRect(renderer, &sdlRect);
    SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, color->a);

    SDL_RenderPresent(renderer);
}

int Renderer::ShowWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Classic Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

void Renderer::HandleInput()
{

}

void Renderer::Destroy()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

