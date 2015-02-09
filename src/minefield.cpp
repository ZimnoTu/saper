#include "minefield.h"
#include <iostream>
#include <vector>

MineField::MineField()
{
    horizontalLength = 5;
    verticalLength = 5;
    numberOfBombs = 4;
    makeVector();
}

MineField::MineField(int horizontal, int vertical) : horizontalLength(horizontal), verticalLength(vertical)
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

void MineField::drawField()
{
    drawLetters();
    drawDashes();
    for(uint32_t i=0; i < field.size(); i++)
    {
        for(uint32_t j =0; j < field.at(i).size(); j++)
        {
           if(j==0)
           {
               drawNumberAndFrame(i,j);
           }
           std::cout << field.at(i).at(j) << " ";
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
            return false;
    else
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
