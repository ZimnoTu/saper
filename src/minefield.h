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
    void putTheBomb(unsigned int x, unsigned int y);
    bool isBombPlaced(unsigned int x, unsigned int y);
    int countBombs();
    int countBombsInRow(std::vector<int> &row);
    void putRandomBombs();
    int showFieldValue(unsigned int x, unsigned int y);
    void checkIfbombIsAround();
    bool isOutOfVector(int x, int y);

//MineFieldDrawer



//
    void checkingFieldsAround(unsigned int j, unsigned int i);
private:
    unsigned int horizontalLength;
    unsigned int verticalLength;
    unsigned int numberOfBombs;
    std::vector<std::vector<int>> field;
    void makeVector();
    const int bomb;

    bool isBomb(int &element);

    friend class mineFieldDrawer;
};
