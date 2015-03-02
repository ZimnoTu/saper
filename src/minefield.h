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
    void setParameters(int _horizontalLength, int _verticalLength);
    int getHorizontalLength();
    int getVerticalLength();
    int getFieldValue (unsigned int horizontalParameter, unsigned int verticalParameter);
    void setFieldValue (unsigned int horizontalParameter , unsigned int verticalParameter, int value);
    void setField2Uncovered (unsigned int horizontalParameter , unsigned int verticalParameter);
    void setField2Flagged (unsigned int horizontalParameter, unsigned int verticalParameter);
    void uncoverFields(unsigned int horizontalParameter, unsigned int verticalParameter);
    void uncoverAll(unsigned int horizontalParameter, unsigned int verticalParameter);
    StateOFField getFieldState(unsigned int horizontalParameter, unsigned int verticalParameter);

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

    void incraseIfBomb(int bombCounter);
    int getnumberOfHiddenFields();
    int getnumberOfBombs();
    void eraseFields();

    void uncoverAllBombs();
    void uncoverFieldsAroundByRecurrence(unsigned int horizontalParameter, unsigned int verticalParameter);
private:
    unsigned int horizontalLength;
    unsigned int verticalLength;
    unsigned int numberOfBombs;
    std::vector<std::vector<SmallField>> field;
    const int bomb;
    const int maxVertical = 99;
    const int maxHorizontal = 26;

    void makeVector();
    bool isBomb(int &element);

    friend class MineFieldDrawer;
};
