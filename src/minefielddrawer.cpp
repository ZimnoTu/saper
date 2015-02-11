#include "minefielddrawer.h"

void MineFieldDrawer::drawField(MineField &mineField)
{
    drawLetters(mineField);
    drawDashes(mineField);
    for (auto vertical = 0; vertical < mineField.getVerticalLength(); vertical++)
    {
        for (auto horizontal = 0; horizontal < mineField.getHorizontalLength(); horizontal++)
        {
            if (horizontal == 0)
                drawNumberAndFrame(mineField,vertical, horizontal);
            if (mineField.showFieldValue(horizontal,vertical) == mineField.bomb)
                std::cout<< "X ";
            else if (mineField.showFieldValue(horizontal,vertical) == 0)
                std::cout<< "  ";
            else
                std::cout << mineField.showFieldValue(horizontal,vertical) << " ";
            if (horizontal == mineField.getHorizontalLength()-1)
                drawNumberAndFrame(mineField,vertical, horizontal);
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
    for (auto horizontal =0; horizontal < mineField.getHorizontalLength(); horizontal++)
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
    for(auto horizontal =0; horizontal < mineField.getHorizontalLength(); horizontal++)
    {
        if (horizontal== mineField.getHorizontalLength() -1)
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
