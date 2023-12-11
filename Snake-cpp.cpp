#include "Game.h"
#include "IConsumablesGenerator.h"
#include "IncreaseSpeedConsumable.h"
#include "InscreaseSizeConsumable.h"
#include "RandomConsumablesGenerator.h"
#include "SDLRenderer.h"
#include "Utils.h"

Game* game = nullptr;
Renderer* renderer = nullptr;
IConsumablesGenerator* consumablesGenerator = nullptr;

void NewGame();

int main()
{
    renderer = new SDLRenderer(640, 480);

    NewGame();

    renderer->ShowWindow();

    bool running = true;

    while (running)
    {
		running = renderer->Render();
        game->Run();
    }

    Utils::Debug("End program");

    delete consumablesGenerator;
    delete game;
    delete renderer;

    return 0;
}

void NewGame()
{
    delete consumablesGenerator;
	delete game;

    game = nullptr;
    consumablesGenerator = nullptr;

    Utils::Debug("Game began!");

    int rows = 25;
    int columns = 25;
    int initialSnakeSegments = 5;
    MoveDirection initialDirection = Up;

    consumablesGenerator = new RandomConsumablesGenerator();
    consumablesGenerator->consumables.push_back(new IncreaseSizeConsumable());
    consumablesGenerator->consumables.push_back(new IncreaseSpeedConsumable());

    game = new Game(rows, columns, initialSnakeSegments, initialDirection, renderer, consumablesGenerator, NewGame);
}