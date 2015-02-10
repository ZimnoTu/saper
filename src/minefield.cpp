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
        throw std::string("Ojoj za duzo!");
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

void MineField::drawField()
{
    drawLetters();
    drawDashes();
    for(uint32_t i=0; i < field.size(); i++)
    {
        for(uint32_t j = 0; j < field.at(i).size(); j++)
        {
           if (j == 0)
           {
               drawNumberAndFrame(i, j);
           }
           if(field[i][j] == 9)std::cout<< "X ";
           else std::cout << field.at(i).at(j) << " ";
           if(j==field.at(i).size()-1)
           {
               drawNumberAndFrame(i, j);
           }
        }
        std::cout<<std::endl;
    }
    drawDashes();
    drawLetters();
    return;
}

void MineField::drawLetters()
{
    char letter = 'A';
    std::cout<<"    ";
    for(uint32_t j=0; j < horizontalLength; j++)
    {
        std::cout << letter << " ";
        letter++;
    }
    std::cout << std::endl;
    return;
}

void MineField::drawDashes()
{
    std::cout<<"    ";
    for(unsigned int j=0; j < horizontalLength; j++)
    {
        if (j== horizontalLength -1)
            std::cout<<"-";
        else
            std::cout<<"--";
    }
    std::cout<<std::endl;
    return;
}

void MineField::drawNumberAndFrame(uint32_t numberOfRow, uint32_t numberOfColumn)
{
    if(numberOfColumn == 0)
    {
        drawNumber(numberOfRow);
        std::cout << "| ";
    }
    else if(numberOfColumn == horizontalLength-1)
    {
        std::cout<< "| ";
        drawNumber(numberOfRow);
    }
    return;
}

void MineField::drawNumber(uint32_t numberOfRow)
{
    if(numberOfRow < 9)
        std::cout<< numberOfRow+1 << " ";
    else
        std::cout<< numberOfRow+1;
    return;
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
        y = rand()%verticalLength-1;
        x = rand()%horizontalLength-1;
        putTheBomb(x,y);
    }
}

int MineField::showFieldValue(unsigned int x, unsigned int y)
{
    return field[y][x];
}

void MineField::incrementFieldsArround(unsigned int j, unsigned int i)
{
    for (auto l =-1; l< 2; l++)
        for(int k =-1; k< 2; k++)
            if(field[i+l][j+k] !=9) field[i+l][j+k] ++;
}

void MineField::setDigits()
{
    for(unsigned int i =0; i< verticalLength; i++)
        for(unsigned int j = 0; j< horizontalLength; j++)
            if (showFieldValue(j, i)==9)
                incrementFieldsArround(j, i);
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
