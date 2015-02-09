#ifndef MINEFIELD_H
#define MINEFIELD_H
#include <vector>
#include <iostream>

class MineField
{
private:
    unsigned int horizontalLength;
    unsigned int verticalLength;
    unsigned int numberOfBombs;
    std::vector<std::vector<int>> field;
    void makeVector();

public:
    MineField();
    MineField(int horizontal, int vertical);
    int getHorizontalLength();
    int getVerticalLength();

    bool isBombPossible();
    void setNumberOfBombs(int _numberOfBombs);
    void drawField();
    void drawLetters();
    void drawDashes();
    void drawNumberAndFrame(uint32_t nuberOfRow,uint32_t numberOfColumn);
    void drawNumber(uint32_t nuberOfRow);
};

#endif // MINEFIELD_H
