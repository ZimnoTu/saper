#include "minefielddrawer.h"

void MineFieldDrawer::drawField(MineField &mineField)
{
    drawLetters(mineField);
    drawDashes(mineField);
    for(auto i=0; i < mineField.getVerticalLength(); i++)
    {
        for (auto j = 0; j < mineField.getHorizontalLength(); j++)
        {
            if (j == 0)
                drawNumberAndFrame(mineField,i, j);
            if (mineField.showFieldValue(j,i) == 9)
                std::cout<< "X ";
            else if (mineField.showFieldValue(j,i) == 0)
                std::cout<< "  ";
            else
                std::cout << mineField.showFieldValue(j,i) << " ";
            if (j==mineField.getHorizontalLength()-1)
                drawNumberAndFrame(mineField,i, j);
        }
        std::cout<<std::endl;
    }
    drawDashes(mineField);
    drawLetters(mineField);
    return;
}

void MineFieldDrawer::drawLetters(MineField &mineField)
{
    char letter = 'A';
    std::cout<<"    ";
    for(auto j=0; j < mineField.getHorizontalLength(); j++)
    {
        std::cout << letter << " ";
        letter++;
    }
    std::cout << std::endl;
    return;
}

void MineFieldDrawer::drawDashes(MineField &mineField)
{
    std::cout<<"    ";
    for(auto j=0; j < mineField.getHorizontalLength(); j++)
    {
        if (j== mineField.getHorizontalLength() -1)
            std::cout<<"-";
        else
            std::cout<<"--";
    }
    std::cout<<std::endl;
    return;
}

void MineFieldDrawer::drawNumberAndFrame(MineField &mineField, unsigned int numberOfRow, unsigned int numberOfColumn)
{
    if(numberOfColumn == 0)
    {
        drawNumber(numberOfRow);
        std::cout << "| ";
    }
    else if((int)numberOfColumn == mineField.getHorizontalLength()-1)
    {
        std::cout<< "| ";
        drawNumber(numberOfRow);
    }
    return;
}

void MineFieldDrawer::drawNumber(unsigned numberOfRow)
{
    if(numberOfRow < 9)
        std::cout<< numberOfRow+1 << " ";
    else
        std::cout<< numberOfRow+1;
    return;
}
