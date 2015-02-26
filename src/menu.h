#pragma once
#include "game.h"

class Menu
{
public:
   // Menu Menu();

    void displayMenu();
    void setOwnField();

    void playBeginerLvl();
    void playIntermediateLvl();
    void playExpertLvl();
    void playOwnLvl();
    void selectedInvalidOption();
private:
    int chosenPosition;
    Game game;
};
