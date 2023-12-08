#include "Game.h"
#include "SDLRenderer.h"
class Cell;

int main()
{
    int rows = 25;
    int columns = 25;
    int initialSnakeSegments = 5;
    MoveDirection moveDirection = Up;

    const auto renderer = new SDLRenderer(640,480);
    const auto game = new Game(rows, columns, initialSnakeSegments, moveDirection, renderer);

    renderer->ShowWindow();

    bool running = true;

    while (running)
    {
        running = renderer->Render();
        game->Run();
    }

    delete game;
    delete renderer;

    return 0;
}
