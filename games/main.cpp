#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "hangman.h"
#include "tictactoe.h"
using namespace std;

int main()
{
    int gameChoice;
    cout << "Welcome to the Gameboard!\n";

    while (true)
    {
        cout << "Please choose a game:\n";
        cout << "1. Tic Tac Toe\n";
        cout << "2. Hangman\n";
        cout << "3. Exit\n";
        cin >> gameChoice;

        // Tic Tac Toe
        if (gameChoice == 1)
        {
            TicTacToe tictactoe;
            system("cls");
            tictactoe.playGame();
            cout << "\n";
        }
        // Hangman
        else if (gameChoice == 2)
        {
            Hangman hangman;
            system("cls");
            hangman.playGame();
            cout << "\n";
        }
        // Exit
        else if (gameChoice == 3)
        {
            return 0;
        }
    }
}