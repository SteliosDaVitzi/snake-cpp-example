#include <iostream>
#include <string>
#include "Game.h"
#include "Renderer.h"
#include "Grid.h"
#include "Cell.h"
class Cell;
using namespace std;

GameState current_state = NotStarted;

void print(const string& string_message);
void get_user_choice_to_start_game();

Cell* clickedCell = nullptr;
Game* game = nullptr;

// Function to check if a point is inside a rectangle
bool pointInsideRect(int x, int y, const SDL_Rect& rect) {
    return x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h;
}

void handleMouseClick(int mouseX, int mouseY) {
    // Check if the mouse click is inside any of the cells
    for (Cell* cell : game->GetGrid()->GetCells()) {
        SDL_Rect rect;
        rect.x = cell->rect.position.X;
        rect.y = cell->rect.position.Y;
        rect.w = 10;
        rect.h = 10;
        if (pointInsideRect(mouseX, mouseY, rect)) {
            clickedCell = cell;
            cout << "cell clicked : " << cell->GetRow() << "," << cell->GetColumn() << endl;
            break;
        }
    }
}

int main()
{
    print("Do you want to start a new game? y or n");

    //get_user_choice_to_start_game();

    int rows = 15;
    int columns = 15;
    int initialSnakeSegments = 5;
    MoveDirection initialDirection = Up;

    auto renderer = new Renderer();
    game = new Game(rows, columns, initialSnakeSegments, initialDirection, renderer);

    renderer->ShowWindow();

    current_state = InProgress;

    bool programRunning = current_state == InProgress;

    while (programRunning)
    {
        game->Render();
        game->Run();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                programRunning = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);

                // Handle mouse click
                handleMouseClick(mouseX, mouseY);
            }
        }
    }

    delete game;
    game = nullptr;

    renderer->Destroy();

    delete renderer;
    renderer = nullptr;

    return 0;
}

void print(const string& string_message)
{
    cout << string_message << endl;
}

void get_user_choice_to_start_game()
{
    char choice;

    cin >> choice;

    if (choice == 'y')
        current_state = InProgress;
    else if (choice == 'n')
        current_state = NotStarted;
    else
        print("Invalid choice");
}
