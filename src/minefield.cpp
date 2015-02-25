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
    if(horizontalLength > 26 || verticalLength > 99)
        return false;
    return true;
}

void MineField::setParameters(int _horizontalLength, int _verticalLength)
{
    horizontalLength = _horizontalLength;
    verticalLength = _verticalLength;
    numberOfBombs = (_horizontalLength*_verticalLength)/10;
    makeVector();
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

void MineField::uncoverField(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    field[verticalParameter][horizontalParameter].covered = false;
}

void MineField::uncoverFieldsAround(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    if (!isOutOfVector(horizontalParameter, verticalParameter) &&
            isFieldCovered(horizontalParameter, verticalParameter))
    {
        uncoverField(horizontalParameter, verticalParameter);
        if (getFieldValue(horizontalParameter, verticalParameter) == 0)
        {
            std::vector<int> positions = {-1, 0, 1};
            for(auto vPosition : positions)
                for(auto hPosition : positions)
                    uncoverFieldsAround(horizontalParameter + hPosition, verticalParameter + vPosition);
        }
    }
}


bool MineField::isFieldCovered(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    return field[verticalParameter][horizontalParameter].covered;
}

void MineField::putTheBomb(unsigned int horizontalParameter, unsigned int verticalParameter)
{
   if (horizontalParameter>horizontalLength || verticalParameter>verticalLength ||
           isBombPlaced(horizontalParameter, verticalParameter))
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
void MineField::checkingFieldsAround(unsigned int horizontalParameter, unsigned int verticalParameter)
{
    std::vector<int> positions = {-1, 0, 1};
    for (auto vPosition : positions)
        for (auto hPosition : positions)
            if(!isOutOfVector (horizontalParameter + hPosition, verticalParameter + vPosition))
                if (getFieldValue(horizontalParameter + hPosition, verticalParameter + vPosition) == bomb)
                    setFieldValue(horizontalParameter, verticalParameter, 1);
}

int MineField::getnumberOfUncoveredFields()
{
    int numberOfUncoveredField = 0;
    for (unsigned int vertical = 0; vertical< verticalLength; vertical++)
        for (unsigned int horizontal = 0; horizontal< horizontalLength; horizontal++)
            if (isFieldCovered(horizontal, vertical))
              ++numberOfUncoveredField;
    return numberOfUncoveredField;
}

int MineField::getnumberOfBombs()
{
    return numberOfBombs;
}

void MineField::uncoverAllBombs()
{
    for (unsigned int vertical = 0; vertical< verticalLength; vertical++)
        for (unsigned int horizontal = 0; horizontal< horizontalLength; horizontal++)
            if (getFieldValue(horizontal, vertical) == bomb )
                uncoverField(horizontal, vertical);
}

void MineField::checkIfbombIsAround()
{
    for (unsigned int vertical = 0; vertical< verticalLength; vertical++)
        for (unsigned int horizontal = 0; horizontal< horizontalLength; horizontal++)
            if (getFieldValue(horizontal, vertical) != bomb )
                checkingFieldsAround(horizontal, vertical);
}

bool MineField::isOutOfVector(int horizontalParameter, int verticalParameter)
{
    if (verticalParameter < 0 || verticalParameter > verticalLength - 1 ||
            horizontalParameter < 0 || horizontalParameter > horizontalLength - 1)
        return true;
    return false;
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
