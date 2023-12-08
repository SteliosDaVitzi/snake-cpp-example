#include <iostream>
#include <string>
#include "Game.h"
#include "Renderer.h"
#include "Grid.h"
#include "Cell.h"
#include "SDLRenderer.h"
class Cell;
using namespace std;

int main()
{
    GameState current_state = NotStarted;

    Cell* clickedCell = nullptr;
    Game* game = nullptr;

    int rows = 15;
    int columns = 15;
    int initialSnakeSegments = 5;
    MoveDirection moveDirection = Up;

    const auto renderer = new SDLRenderer(640,480);

    game = new Game(rows, columns, initialSnakeSegments, moveDirection, renderer);

    renderer->ShowWindow();

    current_state = InProgress;

    bool running = current_state == InProgress;

    while (running)
    {
        running = renderer->Render();
        game->Run();
    }

    delete game;
    delete renderer;

    return 0;
}
