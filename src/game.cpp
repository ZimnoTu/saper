#include "game.h"
#include <iostream>
#include <thread>

void Game::setParameters(int horizontalLength, int verticalLength)
{
    mineField.setParameters(horizontalLength, verticalLength);
}

void Game::startGame()
{
    mineField.putRandomBombs();
    mineField.checkIfbombIsAround();
}

std::string Game::parseInput(std::string input)
{
    std::string processedInput;
    processedInput = inputHndlr.processInput(input);
    return processedInput;
}

int Game::getMaxHorizontalSize()
{
    return mineField.getMaxHorizontal();
}

int Game::getMaxVerticalSize()
{
    return mineField.getMaxVertical();
}

bool Game::isMoveValid()
{
    if(inputHndlr.getHorizontalParameter() > mineField.getHorizontalLength()
            || inputHndlr.getHorizontalParameter() < 0)
        return false;
    if(inputHndlr.getVerticalParameter() > mineField.getVerticalLength()
            || inputHndlr.getVerticalParameter() < 0)
        return false;
    return true;
}

bool Game::isBomb(unsigned int presentHorizontalMove, unsigned int presentVerticalMove)
{
    return mineField.isBombHere(presentHorizontalMove, presentVerticalMove);
}

bool Game::makeMove(std::string &str)
{
    std::string processedInput = parseInput(str);
    bool flag = inputHndlr.isFlagDemanded(str);

    if (isMoveValid())
    {
        presentHorizontalMove = inputHndlr.getHorizontalParameter();
        presentVerticalMove = inputHndlr.getVerticalParameter();
        if(flag)
        {
            mineField.setField2Flagged(presentHorizontalMove, presentVerticalMove);
            return false;
        }
        else if(isBomb(presentHorizontalMove, presentVerticalMove))
        {
            mineField.uncoverAllBombs();
            return true;
        }
        else
        {
            mineField.uncoverFields(presentHorizontalMove,presentVerticalMove);
            return false;
        }
    }
    else
        return 0;
}

StateOFField Game::isFieldCovered()
{
    return mineField.getFieldState(presentHorizontalMove, presentVerticalMove);
}
StateOFField Game::isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    return mineField.getFieldState(horizontalParameter, verticalParameter);
}

void Game::draw()
{
    mineFieldDrawer.drawField(mineField);
}

void Game::checkingField()
{
    mineField.checkIfbombIsAround();
}

void Game::placeBomb(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    mineField.putTheBomb(horizontalParameter,verticalParameter);
}

int Game::getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    mineField.getFieldValue(horizontalParameter, verticalParameter);
}

std::string Game::cleanBufforAndTakeMove()
{
    std::string move;
    do
    {
        std::getline(std::cin, move);
    }
    while(move == "");

    return move;
}

void Game::play()
{
    startGame();
    int exit = 0;

    while (mineField.getnumberOfBombs() != mineField.getnumberOfHiddenFields() &&
            !exit)
    {
        draw();
        std::cout << "Your move: ";
        std::string move = cleanBufforAndTakeMove();
        exit = makeMove(move);
        if(exit)
        {
            draw();
            std::cout<< "Loser!!!\n";
        }
    }
    if(!exit)
    {
        draw();
        winner();
    }
}

void Game::winner()
{
    std::cout << "WINNER!\n";
    std::cout <<" \n";
    std::cout <<"             @@@\n";
    std::cout <<"             @@@                     \n";
    std::cout <<"           @@@@@@@,                  \n";
    std::cout <<"            @@@@@@++:`               \n";
    std::cout <<"            @@@@@@   `+@+            \n";
    std::cout <<"              @@+.      `@           \n";
    std::cout <<"               `         @           \n";
    std::cout <<"                         @           \n";
    std::cout <<"             .#@'`   @. +            \n";
    std::cout <<"          `@@@@@@@@@@@@;#            \n";
    std::cout <<"         @@@@@@@@@@@@@@@.            \n";
    std::cout <<"        @@@@@@@@@@@@@@@@@`           \n";
    std::cout <<"       @@@@@@@@@@@@@@@@@;            \n";
    std::cout <<"      `@@@@@@@@@@@@@@@@@             \n";
    std::cout <<"      @@@@@@@@@@@@@@@@@@:            \n";
    std::cout <<"      @@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"     ,@@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"     #@@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"     @@@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"     '@@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"     `@@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"      @@@@@@@@@@@@@@@@@@@            \n";
    std::cout <<"      @@@@@@@@@@@@@@@@@@             \n";
    std::cout <<"       @@@@@@@@@@@@@@@@@             \n";
    std::cout <<"       ,@@@@@@@@@@@@@@@              \n";
    std::cout <<"        '@@@@@@@@@@@@@               \n";
    std::cout <<"         `@@@@@@@@@@@                \n";
    std::cout <<"           :@@@@@@@                  \n";
    std::cout <<" \n";
}

void Game::eraseMinefield()
{
    mineField.eraseFields();
}
