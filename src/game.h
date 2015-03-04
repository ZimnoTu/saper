#pragma once
#include "inputhandler.h"
#include "minefield.h"
#include "minefielddrawer.h"

class Game
{
public:
    void setParameters(int horizontalLength, int verticalLength);
    void startGame();
    bool isMoveValid();
    bool isBomb(unsigned int presentHorizontalMove, unsigned int presentVerticalMove);
    void placeBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    void checkingField();
    int getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter);
    std::string parseInput (std::string input);
    int getMaxHorizontalSize();
    int getMaxVerticalSize();

    bool makeMove(std::string &str);
    StateOFField isFieldCovered();
    StateOFField isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter);
    void draw();
    void winner();
    void probaWatku();
    void eraseMinefield();

    void play();



    std::string getMove(std::string move);
    std::string cleanBufforAndTakeMove();
private:

    unsigned int presentHorizontalMove;
    unsigned int presentVerticalMove;

    MineField mineField;
    InputHandler inputHndlr;
    MineFieldDrawer mineFieldDrawer;
    const int bomb = 9;


};
