#include <iostream>
#include <cstdlib>
#include<ctime>
#include "minefield.h"


int main()
{
   // srand(time(0)); ///TUTAJ COS NIE DZIALA!!!!!
   // std::cout<< rand()%100 << std::endl;
    MineField mf(10,5);
   // mf.putRandomBombs();
    mf.putTheBomb(0,0);
    mf.putTheBomb(4,2);
    mf.setDigits();


    mf.drawField();


    return 0;
}
