#include "drawfield.h"

void DrawField::drawField()
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
           //std::cout << 0 << " ";
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

void DrawField::drawLetters()
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
