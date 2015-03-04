#include "minefielddrawer.h"

void MineFieldDrawer::drawField(MineField &mineField)
{
    system("clear");
    drawLetters(mineField);
    drawDashes(mineField);    
    for (auto vertical = 0; vertical < mineField.getVerticalLength(); vertical++)
    {
        for (auto horizontal = 0; horizontal < mineField.getHorizontalLength(); horizontal++)
        {
            if (horizontal == 0)
                drawNumberAndFrame(mineField, vertical, horizontal);
            if (mineField.getFieldState(horizontal, vertical) == StateOFField::covered)
                std::cout << ". ";
            else if (mineField.getFieldState(horizontal, vertical) == StateOFField::flag)
                std::cout << "F ";
            else
            {
                if (mineField.getFieldValue(horizontal, vertical) == mineField.bomb)
                    std::cout<< "X ";
                else if (mineField.getFieldValue(horizontal, vertical) == 0)
                    std::cout<< "  ";
                else
                    std::cout << mineField.getFieldValue(horizontal, vertical) << " ";
            }
            if (horizontal == mineField.getHorizontalLength() - 1)
                drawNumberAndFrame(mineField, vertical, horizontal);
        }
        std::cout<<std::endl;
    }
    drawDashes(mineField);
    drawLetters(mineField);
    displayAdditionalInformation(mineField);
}

void MineFieldDrawer::drawLetters(MineField &mineField)
{
    char letter = 'A';
    std::cout << "    ";
    for (auto horizontal = 0; horizontal < mineField.getHorizontalLength(); horizontal++)
    {
        std::cout << letter << " ";
        letter++;
    }
    std::cout << std::endl;
}

void MineFieldDrawer::drawDashes(MineField &mineField)
{
    std::cout << "    ";
    for(auto horizontal = 0; horizontal < mineField.getHorizontalLength(); horizontal++)
    {
        if (horizontal == mineField.getHorizontalLength() - 1)
            std::cout << "-";
        else
            std::cout << "--";
    }
    std::cout<<std::endl;
}

void MineFieldDrawer::drawNumberAndFrame(MineField &mineField, unsigned int numberOfRow, unsigned int numberOfColumn)
{
    if(numberOfColumn == 0)
    {
        drawNumber(numberOfRow);
        std::cout << "| ";
    }
    else if(static_cast<int>(numberOfColumn) == mineField.getHorizontalLength() - 1)
    {
        std::cout << "| ";
        drawNumber(numberOfRow);
    }
}

void MineFieldDrawer::drawNumber(unsigned numberOfRow)
{
    if(numberOfRow < 9)
        std::cout<< numberOfRow + 1 << " ";
    else
        std::cout<< numberOfRow + 1;
}

void MineFieldDrawer::displayAdditionalInformation(MineField &mineField)
{
    std::cout << "Number of bombs: " << mineField.getnumberOfBombs() << std::endl;
    std::cout << "Number of uncovered fields: " << mineField.getnumberOfHiddenFields() << std::endl;
}
