#include "game.h"

Game::Game() : mineField(10, 10){ }

Game::Game(int horizontalLenght, int verticalLenght) : mineField(horizontalLenght, verticalLenght){ }

void Game::startGame()
{
    mineField.putRandomBombs();
    mineField.checkIfbombIsAround();
}

bool Game::isMoveValid(std::string str)
{
    inputHndlr.processImput(str);
    if(inputHndlr.getHorizontalParameter() > mineField.getHorizontalLength())
        return false;
    if(inputHndlr.getVerticalParameter() > mineField.getVerticalLength())
        return false;
    return true;
}

void Game::makeMove(std::string str)
{
    if (isMoveValid(str))
        mineField.setFieldStatus(inputHndlr.getHorizontalParameter(), inputHndlr.getVerticalParameter());
}

bool Game::isFieldCovered()
{
    return mineField.isFieldCovered(inputHndlr.getHorizontalParameter(),inputHndlr.getVerticalParameter());
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
