#include <iostream>
#include <string>
#include <limits>
#include "game.h"
using namespace std;

class TicTacToe : public Game
{
private:
    // Create a 3x3 gameboard with numbers. Users will choose a number to indicate the spot they want to play
    char gameboard[3][3] = {{'1', '2', '3'},
                            {'4', '5', '6'},
                            {'7', '8', '9'}};
    int selectedRow;
    int selectedColumn;
    char token = 'x';
    bool tiedGame = false;
    string player1;
    string player2;

    // Display a tic tac toe board to the console, using the values from the gameboard
    void displayGameboard()
    {
        system("cls");
        cout << player1 << " is player 1 so they will go first \n";
        cout << player2 << " is player 2 so they will go second \n";
        cout << "     |     |     \n";
        cout << "  " << gameboard[0][0] << "  |  " << gameboard[0][1] << "  |  " << gameboard[0][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << gameboard[1][0] << "  |  " << gameboard[1][1] << "  |  " << gameboard[1][2] << "  \n";
        cout << "_____|_____|_____\n";
        cout << "     |     |     \n";
        cout << "  " << gameboard[2][0] << "  |  " << gameboard[2][1] << "  |  " << gameboard[2][2] << "  \n";
        cout << "     |     |     \n";
    }

    // Take a turn. Get input from user and process it
    void takeTurn()
    {
        bool isInvalid = false;
        int digit;
        // Get user input and make sure it is an integer
        if (token == 'x')
        {
            while ((cout << player1 << ", make your move") && !(cin >> digit))
            {
                cout << "That's not a valid option. Try again.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            }
        }
        if (token == 'o')
        {
            while ((cout << player2 << ", make your move") && !(cin >> digit))
            {
                cout << "That's not a valid option. Try again.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            }
        }

        // Once we know we have an integer, update the row and column so we know which value in the gameboard variable to update
        switch (digit)
        {
        case 1:
            selectedRow = 0;
            selectedColumn = 0;
            break;
        case 2:
            selectedRow = 0;
            selectedColumn = 1;
            break;
        case 3:
            selectedRow = 0;
            selectedColumn = 2;
            break;
        case 4:
            selectedRow = 1;
            selectedColumn = 0;
            break;
        case 5:
            selectedRow = 1;
            selectedColumn = 1;
            break;
        case 6:
            selectedRow = 1;
            selectedColumn = 2;
            break;
        case 7:
            selectedRow = 2;
            selectedColumn = 0;
            break;
        case 8:
            selectedRow = 2;
            selectedColumn = 1;
            break;
        case 9:
            selectedRow = 2;
            selectedColumn = 2;
            break;
        default:
            cout << "Invalid input" << endl;
            isInvalid = true;
            break;
        }

        if (isInvalid)
            return;

        // Update the value in the gameboard to the user's token
        if (token == 'x' && gameboard[selectedRow][selectedColumn] != 'x' && gameboard[selectedRow][selectedColumn] != 'o')
        {
            gameboard[selectedRow][selectedColumn] = 'x';
            token = 'o';
        }
        else if (token == 'o' && gameboard[selectedRow][selectedColumn] != 'x' && gameboard[selectedRow][selectedColumn] != 'o')
        {
            gameboard[selectedRow][selectedColumn] = 'o';
            token = 'x';
        }
        // If the spot is taken, let them retry their turn
        else
        {
            cout << "There is no empty gameboard here" << endl;
            takeTurn();
        }
    }

    // check if game has been won, or if there is no more spaces to play
    bool checkGameOver()
    {
        for (int i = 0; i < 3; i++)
        {
            // check if the selectedRow values are the same
            bool selectedRowsSame = gameboard[i][0] == gameboard[i][1] && gameboard[i][0] == gameboard[i][2];
            if (selectedRowsSame)
            {
                return true;
            }
            // check if selectedColumn values are the same
            bool selectedColumnsSame = gameboard[0][i] == gameboard[1][i] && gameboard[0][i] == gameboard[2][i];
            if (selectedColumnsSame)
            {
                return true;
            }
            // // check if diagonal values are the same
            if (gameboard[0][0] == gameboard[1][1] && gameboard[0][0] == gameboard[2][2])
            {
                return true;
            }
            // // check if other diagonal values are the same
            if (gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0])
            {
                return true;
            }
        }

        // See if there are any open spots left to play
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (gameboard[i][j] != 'x' && gameboard[i][j] != 'o')
                {
                    // If there are any empty slots in the gameboard, we can still keep playing
                    return false;
                }
            }
        }

        tiedGame = true;
        return true;
    }

public:
    void playGame()
    {
        // Get user info
        cout << "Enter the name of the first player: \n";
        cin >> player1;
        cout << "Enter the name of the second player: \n";
        cin >> player2;
        cout << player1 << " is player 1 so they will go first \n";
        cout << player2 << " is player 2 so they will go second \n";

        // Keep taking turns until we know the game is over
        while (!checkGameOver())
        {
            displayGameboard();
            takeTurn();
        }

        // Print out end of game message (who wins or tie)
        if (token == 'x' && !tiedGame)
        {
            cout << "Nice job " << player2 << "! You win!";
        }
        else if (token == 'o' && !tiedGame)
        {
            cout << "Nice job " << player1 << "! You win!";
        }
        else
        {
            cout << "It's a tie";
        }
    }
};
