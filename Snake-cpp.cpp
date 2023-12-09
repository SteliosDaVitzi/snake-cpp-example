#include "Game.h"
#include "IConsumablesGenerator.h"
#include "IncreaseSpeedConsumable.h"
#include "InscreaseSizeConsumable.h"
#include "RandomConsumablesGenerator.h"
#include "SDLRenderer.h"

int main()
{
    int rows = 25;
    int columns = 25;
    int initialSnakeSegments = 5;
    MoveDirection initialDirection = Up;

    const auto renderer = new SDLRenderer(640,480);

    const auto consumablesGenerator = new RandomConsumablesGenerator();
    consumablesGenerator->consumables.push_back(new IncreaseSizeConsumable());
    consumablesGenerator->consumables.push_back(new IncreaseSpeedConsumable());

    const auto game = new Game(rows, columns, initialSnakeSegments, initialDirection, renderer, consumablesGenerator);

    renderer->ShowWindow();

    bool running = true;

    while (running)
    {
		running = renderer->Render();

        game->Run();
    }

    delete consumablesGenerator;
    delete game;
    delete renderer;

    return 0;
}
