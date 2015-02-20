#pragma once
#include "inputhandler.h"
#include "minefield.h"
#include "minefielddrawer.h"

class Game
{
public:
    Game();
    Game(int horizontalLenght, int verticalLenght);
    void startGame();
    bool isMoveValid(std::string &str);
    void placeBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    void checkingField();
    int getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter);

    int makeMove(std::string &str);
    bool isFieldCovered();
    bool isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter);
    void draw();

    void play();



private:

    unsigned int presentHorizontalMove;
    unsigned int presentVerticalMove;

    MineField mineField;
    InputHandler inputHndlr;
    MineFieldDrawer mineFieldDrawer;


};
