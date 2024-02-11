#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "game.h"
using namespace std;

class Hangman : public Game
{
private:
    // Credit for art - https://gist.github.com/chrishorton/8510732aa9a80a03c829b09f12e20d9c
    string hangmanArt[7] = {
        " +---+\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "     |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        " |   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|   |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "     |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/    |\n"
        "     |\n"
        "==========",
        " +---+\n"
        " |   |\n"
        " O   |\n"
        "/|\\  |\n"
        "/ \\  |\n"
        "     |\n"
        "=========="};
    int numberOfMisses = 0;
    char guess;
    string secretWord = "";
    string guessWord = "";
    // list of words
    vector<string> words = {"programming", "hangman", "games"};

    string getRandomWord(vector<string> &words)
    {
        return words[rand() % words.size()];
    }
    // Display a hangman board to the console, based on the number of tries
    virtual void displayGameboard()
    {
        system("cls");
        cout << "Welcome to Hangman!\n";
        // show art
        cout << hangmanArt[numberOfMisses] << "\n";
        // Print out the word being guessed
        cout << guessWord << "\n";
    }

    // Take a turn. Get input from user and process it
    virtual void takeTurn()
    {
        // Get user input
        cout << "Enter your guess:\n";
        cin >> guess;

        // If their input is in the word, update the guess word to show their letters
        if (secretWord.find(guess) != string::npos)
        {
            for (int i = 0; i < guessWord.length(); ++i)
            {
                if (secretWord[i] == guess)
                {
                    guessWord[i] = guess;
                }
            }
        }
        // If their guess is not in the word, increment the numberOfMisses
        else
        {
            ++numberOfMisses;
        }
    }

    // check if game has been won, or player has missed too many times
    virtual bool checkGameOver()
    {
        return secretWord == guessWord || numberOfMisses >= 6;
    }

public:
    virtual void playGame()
    {
        secretWord = getRandomWord(words);
        // Make a string of underscores the same length as the secret word
        for (int i = 0; i < secretWord.length(); ++i)
        {
            guessWord += '_';
        }

        // Keep taking turns until we know the game is over
        while (!checkGameOver())
        {
            displayGameboard();
            takeTurn();
        }

        // Print out end of game message (lost or win)
        if (numberOfMisses >= 6)
        {
            displayGameboard();
            cout << "You lost! The word was " << secretWord << "\n";
        }
        else
        {
            displayGameboard();
            cout << "You win! The word was " << secretWord << "\n";
        }
    };
};
