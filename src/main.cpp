#include <iostream>
#include <cstdlib>
#include<ctime>
#include "minefield.h"
#include "minefielddrawer.h"


int main()
{
    srand(time(0)); ///TUTAJ COS NIE DZIALA!!!!!
   // std::cout<< rand()%100 << std::endl;
    MineField mf(10,5);
     mf.putRandomBombs();
    MineFieldDrawer md;

   // mf.putTheBomb(0,0);
    mf.checkIfbombIsAround();
   // mf.putTheBomb(4,2);

    md.drawField(mf);

    //mf.drawField();


    return 0;
}
