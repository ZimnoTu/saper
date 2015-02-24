#include "game.h"

Game::Game() : mineField(10, 10){ }

Game::Game(int horizontalLenght, int verticalLenght) : mineField(horizontalLenght, verticalLenght){ }

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

bool Game::isMoveValid()
{
    if(inputHndlr.getHorizontalParameter() > mineField.getHorizontalLength())
        return false;
    if(inputHndlr.getVerticalParameter() > mineField.getVerticalLength())
        return false;
    return true;
}

int Game::makeMove(std::string &str)
{
    std::string processedInput = parseInput(str);
    if (isMoveValid())
    {
        presentHorizontalMove = inputHndlr.getHorizontalParameter();
        presentVerticalMove = inputHndlr.getVerticalParameter();
        if (getFieldValue(presentHorizontalMove, presentVerticalMove) == 9)
        {
            mineField.uncoverAllBombs();
            return 9;
        }
        else
        {
            mineField.uncoverFieldsAround(presentHorizontalMove,presentVerticalMove);
            return 0;
        }
    }
    else
        return 0;
}

bool Game::isFieldCovered()
{
    return mineField.isFieldCovered(presentHorizontalMove, presentVerticalMove);
}
bool Game::isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    return mineField.isFieldCovered(horizontalParameter, verticalParameter);
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
    std::cout << "Hello! " << std::endl;
    startGame();
    int exit = 0;

    while (mineField.getnumberOfBombs() != mineField.getnumberOfUncoveredFields() &&
            exit == 0)
    {
        std::string move;
        draw();
        std::cout << "Your move: ";
        std::cin >> move;

        exit = makeMove(move);
        if(exit == 9)
        {
            draw();
            std::cout<< "Loser!!!\n";
        }
    }
    if(exit == 0)
        winner();

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
