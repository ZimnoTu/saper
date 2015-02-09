#include <iostream>
#include "minefield.h"


int main()
{
    MineField mf(5,3);
    mf.putTheBomb(0,1);

    mf.drawField();


    return 0;
}
