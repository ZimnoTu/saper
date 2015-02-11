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

void MineField::putTheBomb(unsigned int x, unsigned int y)
{
   if(x>verticalLength || y>horizontalLength )
        return;
    field[y][x] = bomb;
}

bool MineField:: isBombPlaced(unsigned int x, unsigned int y)
{
    if(field[y][x] == bomb)
        return true;
    else
        return false;
}

bool MineField::isBomb(int &element)
{
    return element == bomb;
}

int MineField::countBombsInRow(std::vector<int> &row)
{
    int bombs = 0;
    std::for_each(row.begin(),
                  row.end(),
                  [&](int &element)
    {
        if (isBomb(element))
            ++bombs;
    });
    return bombs;
}

int MineField:: countBombs()
{
    int bombs = 0;
    std::for_each(field.begin(),
                  field.end(),
                  [&](std::vector<int> &row)
    {
        bombs += countBombsInRow(row);
    });

    return bombs;
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
    unsigned int x;
    unsigned int y;
    while ((unsigned int)countBombs()!= numberOfBombs)
    {
        y = rand()%(verticalLength-1);
        x = rand()%(horizontalLength-1);
        putTheBomb(x,y);
    }
}

int MineField::showFieldValue(unsigned int x, unsigned int y)
{
    return field[y][x];
}


void MineField::checkIfbombIsAround()
{
    for(unsigned int i =0; i< verticalLength; i++)
        for(unsigned int j = 0; j< horizontalLength; j++)
            if(showFieldValue(j, i) !=9 )
                checkingFieldsAround(j, i);
}

void MineField::checkingFieldsAround(unsigned int j, unsigned int i)
{
    for (auto l =-1; l< 2; l++)
        for (int k =-1; k< 2; k++)
            if (isOutOfVector(i+l, j+k))
                if (field[i+l][j+k] ==9)
                    field[i][j] ++;
}

bool MineField::isOutOfVector(int x, int y)
{
    if (x<0 || x> verticalLength-1 || y<0 || y>horizontalLength-1)
        return false;
    return true;
}

void MineField::makeVector()
{
    field.resize(verticalLength);
    for(unsigned int i =0; i< verticalLength; i++)
    {
        for(unsigned int j = 0; j< horizontalLength; j++)
            field.at(i).push_back(0);
    }
}
