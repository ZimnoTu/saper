#pragma once
#include <vector>
#include <iostream>
#include "minefielddrawer.h"

class MineField
{
public:
    MineField();
    MineField(int horizontal, int vertical);
    int getHorizontalLength();
    int getVerticalLength();

    bool isBombPossible();
    void setNumberOfBombs(int _numberOfBombs);
    void putTheBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    bool isBombPlaced(unsigned int horizontalParameter, unsigned int verticalParameter);
    int countBombs();
    int countBombsInRow(std::vector<int> &row);
    void putRandomBombs();
    int showFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter);
    void checkIfbombIsAround();
    bool isOutOfVector(int horizontalParameter, int verticalParameter);
    void checkingFieldsAround(unsigned int horizontalParameter, unsigned int verticalParameter);

private:
    unsigned int horizontalLength;
    unsigned int verticalLength;
    unsigned int numberOfBombs;
    std::vector<std::vector<int>> field;
    const int bomb;

    void makeVector();
    bool isBomb(int &element);

    friend class MineFieldDrawer;
};
