#include "game.h"
#include <iostream>
#include <thread>

//Game::Game() : mineField(10, 10){ }

//Game::Game(int horizontalLenght, int verticalLenght) : mineField(horizontalLenght, verticalLenght){ }

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

int Game::makeMove(std::string &str)
{
    std::string processedInput = parseInput(str);
    bool wantFlag = inputHndlr.wantSetFlag(str);

    if (isMoveValid())
    {
        presentHorizontalMove = inputHndlr.getHorizontalParameter();
        presentVerticalMove = inputHndlr.getVerticalParameter();
        if(wantFlag)
        {
            mineField.setField2Flagged(presentHorizontalMove, presentVerticalMove);
            return 0;
        }
        else if (getFieldValue(presentHorizontalMove, presentVerticalMove) == 9)
        {
            mineField.uncoverAllBombs();
            return 9;
        }
        else
        {
            mineField.uncoverFields(presentHorizontalMove,presentVerticalMove);
            return 0;
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

void Game::play()
{
    startGame();
    int exit = 0;

    while (mineField.getnumberOfBombs() != mineField.getnumberOfHiddenFields() &&
            exit == 0)
    {
        std::string move;
        draw();
        std::cout << "Number of bombs: " << mineField.getnumberOfBombs() << std::endl;
        std::cout << "Number of uncovered fields: " << mineField.getnumberOfHiddenFields() << std::endl;
        std::cout << "Your move: ";

        do
        {
            std::getline(std::cin, move);
        }
        while(move == "");

        exit = makeMove(move);
        if(exit == 9)
        {
            draw();
            std::cout<< "Loser!!!\n";
        }
    }
    if(exit == 0)
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
