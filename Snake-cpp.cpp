#include <iostream>
#include <string>
#include "Game.h"
using namespace std;

enum GameState
{
    NotStarted,
    InProgress
};

GameState _currentState = NotStarted;

void print(const string& string_message);
void GetUserChoiceToStartGame();

int main()
{
    print("Do you want to start a new game? y or n");

    GetUserChoiceToStartGame();

    int rows = 5;
    int columns = 5;
    int initialSnakeSegments = 3;
    MoveDirection initialDirection = Up;

    Game* game = new Game(rows, columns, initialSnakeSegments, initialDirection);

    while (_currentState == InProgress) 
    {
        //print("game in progress");
    }

    delete game;
    game = nullptr;
}

void print(const string& string_message)
{
    cout << string_message << endl;
}

void GetUserChoiceToStartGame()
{
    char choice;

    cin >> choice;

    if (choice == 'y')
        _currentState = InProgress;
    else if (choice == 'n')
        _currentState = NotStarted;
    else
        print("Invalid choice");
}
