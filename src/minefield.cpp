#include "minefield.h"
#include <iostream>
#include <vector>
#include <algorithm>

MineField::MineField() : bomb(9)
{
    horizontalLength = 5;
    verticalLength = 5;
    numberOfBombs = 4;
    makeVector();
}

MineField::MineField(int horizontal, int vertical) : horizontalLength(horizontal), verticalLength(vertical), bomb(9)
{
    makeVector();
    numberOfBombs = (horizontal*vertical)/10;
}

bool MineField::isFieldPossible()
{
    if(horizontalLength > 26 || verticalLength > 98)
        return false;
    return true;
}

void MineField::setNumberOfBombs(int _numberOfBombs)
{
    numberOfBombs = _numberOfBombs;
}

int MineField::getHorizontalLength()
{
    return horizontalLength;
}

int MineField::getVerticalLength()
{
    return verticalLength;
}

int MineField::getFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    return field[verticalParameter][horizontalParameter].value;
}

void MineField::setFieldValue(unsigned int horizontalParameter, unsigned int verticalParameter, int value)
{
    field[verticalParameter][horizontalParameter].value += value;
}

void MineField::setFieldStatus(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    field[verticalParameter][horizontalParameter].covered = false;
}

bool MineField::isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    return field[verticalParameter][horizontalParameter].covered;
}

void MineField::putTheBomb(unsigned int horizontalParameter, unsigned int verticalParameter)
{
   if (horizontalParameter>horizontalLength || verticalParameter>verticalLength || isBombPlaced(horizontalParameter, verticalParameter))
       return;

    setFieldValue(horizontalParameter, verticalParameter, bomb);
}

bool MineField:: isBombPlaced(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    if (getFieldValue(horizontalParameter, verticalParameter) == bomb)
        return true;
    else
        return false;
}

bool MineField::isBomb(int &element)
{
    return element == bomb;
}

int MineField::countBombsInRow(std::vector<SmallField> &row)
{
    int bombCounter = 0;
    std::for_each(row.begin(),
                  row.end(),
                  [&](SmallField &element)
    {
        if (isBomb(element.value))
            ++bombCounter;
    });
    return bombCounter;
}

int MineField:: countBombs()
{
    int bombCounter = 0;
    std::for_each(field.begin(),
                  field.end(),
                  [&](std::vector<SmallField> &row)
    {
        bombCounter += countBombsInRow(row);
    });

    return bombCounter;
}

bool MineField::isBombPossible()
{
    if(numberOfBombs >= horizontalLength*verticalLength)
        throw std::string("bomb is not possible");
    else
        return true;
}

void MineField::putRandomBombs()
{
    unsigned int horizontalParameter;
    unsigned int verticalParameter;
    while (static_cast<unsigned int>(countBombs()) != numberOfBombs)
    {
        verticalParameter = rand()%(verticalLength - 1);
        horizontalParameter = rand()%(horizontalLength - 1);
        putTheBomb(horizontalParameter, verticalParameter);
    }
}

void MineField::checkIfbombIsAround()
{
    for (unsigned int vertical = 0; vertical< verticalLength; vertical++)
        for (unsigned int horizontal = 0; horizontal< horizontalLength; horizontal++)
            if (getFieldValue(horizontal, vertical) != bomb )
                checkingFieldsAround(horizontal, vertical);
}

void MineField::checkingFieldsAround(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    for (auto vertVal = -1; vertVal < 2; vertVal++)
        for (int horVal = -1; horVal < 2; horVal++)
            if (isOutOfVector (horizontalParameter + horVal, verticalParameter + vertVal))
                if (getFieldValue(horizontalParameter + horVal, verticalParameter + vertVal) == bomb)
                    setFieldValue(horizontalParameter, verticalParameter, 1);
}

bool MineField::isOutOfVector(int horizontalParameter, int verticalParameter)
{
    if (verticalParameter < 0 || verticalParameter > verticalLength - 1 || horizontalParameter < 0 || horizontalParameter > horizontalLength - 1)
        return false;
    return true;
}

void MineField::makeVector()
{
    if(isFieldPossible())
    {
        field.resize(verticalLength);
        for (unsigned int vertical = 0; vertical < verticalLength; vertical++)
            for(unsigned int horizontal = 0; horizontal < horizontalLength; horizontal++)
                field[vertical].push_back(SmallField());
    }
  //  else
    //    throw std::string("field is too big");
}
