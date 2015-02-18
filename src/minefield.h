#pragma once
#include <vector>
#include <iostream>
#include "minefielddrawer.h"
#include "smallfield.h"

class MineField
{
public:
    MineField();
    MineField(int horizontal, int vertical);
    bool isFieldPossible();
    int getHorizontalLength();
    int getVerticalLength();
    int getFieldValue (unsigned int horizontalParameter, unsigned int verticalParameter);
    void setFieldValue (unsigned int horizontalParameter , unsigned int verticalParameter, int value);

    bool isBombPossible();
    void setNumberOfBombs(int _numberOfBombs);
    void putTheBomb(unsigned int horizontalParameter, unsigned int verticalParameter);
    bool isBombPlaced(unsigned int horizontalParameter, unsigned int verticalParameter);
    int countBombs();
    int countBombsInRow(std::vector<SmallField> &row);
    void putRandomBombs();

    void checkIfbombIsAround();
    bool isOutOfVector(int horizontalParameter, int verticalParameter);
    void checkingFieldsAround(unsigned int horizontalParameter, unsigned int verticalParameter);

private:
    unsigned int horizontalLength;
    unsigned int verticalLength;
    unsigned int numberOfBombs;
    std::vector<std::vector<SmallField>> field;
    const int bomb;

    void makeVector();
    bool isBomb(int &element);

    friend class MineFieldDrawer;
};
