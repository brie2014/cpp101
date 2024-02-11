#include <iostream>
using namespace std;
#pragma once

class Game
{
public:
    virtual void playGame() {}

private:
    virtual void displayGameboard()
    {
    }
    virtual void takeTurn()
    {
    }
    virtual bool checkGameOver()
    {
        return false;
    }
};