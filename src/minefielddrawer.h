#pragma once
#include "minefield.h"

class MineField;
class SmallField;

class MineFieldDrawer
{
public:
    void drawField(MineField &mineField);
    void drawLetters(MineField &mineField);
    void drawDashes(MineField &mineField);
    void drawNumberAndFrame(MineField &mineField, unsigned int nuberOfRow,unsigned int numberOfColumn);
    void drawNumber(unsigned int nuberOfRow);
    void displayAdditionalInformation(MineField &mineField);

};
