#pragma once
#include "inputhandler.h"
#include "minefield.h"
#include "minefielddrawer.h"

class Game
{
public:
    //Game();
    //Game(int horizontalLenght, int verticalLenght);
    void setParameters(int horizontalLength, int verticalLength);
    void startGame();
    bool isMoveValid();
    void placeBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    void checkingField();
    int getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter);
    std::string parseInput (std::string input);

    int makeMove(std::string &str);
    bool isFieldCovered();
    bool isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter);
    void draw();
    void winner();
    void probaWatku();

    void play();



private:

    unsigned int presentHorizontalMove;
    unsigned int presentVerticalMove;

    MineField mineField;
    InputHandler inputHndlr;
    MineFieldDrawer mineFieldDrawer;


};
