#pragma once
#include "inputhandler.h"
#include "minefield.h"

class Game
{
public:
    Game();
    Game(int horizontalLenght, int verticalLenght);
    void startGame();
    bool isMoveValid(std::string str);
    void placeBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    void checkingField();
    int getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter);

    void makeMove(std::string str);
    bool isFieldCovered();





private:
    MineField mineField;
    InputHandler inputHndlr;


};
