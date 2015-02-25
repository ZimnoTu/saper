#pragma once
#include "game.h"

class Menu
{
public:
   // Menu Menu();

    void displayMenu();
    void setOwnField();

private:
    int chosenPosition;
    Game game;
};
