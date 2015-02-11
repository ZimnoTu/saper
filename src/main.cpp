#include <iostream>
#include <cstdlib>
#include<ctime>
#include "minefield.h"
#include "minefielddrawer.h"


int main()
{
    srand(time(0));

    MineField mf(10,10);
    MineFieldDrawer md;

    mf.putRandomBombs();
    mf.checkIfbombIsAround();

    md.drawField(mf);

    return 0;
}
