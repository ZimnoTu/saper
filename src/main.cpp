#include <iostream>
#include <cstdlib>
#include <ctime>
#include "minefield.h"
#include "minefielddrawer.h"
#include "inputhandler.h"

int main()
{
    srand(time(0));

    /*MineField mf(26,10);
    MineFieldDrawer md;
    mf.putRandomBombs();
    mf.checkIfbombIsAround();
    md.drawField(mf);*/

    InputHandler ih;
    std::string str ("18c");
    std::cout << str << std::endl;
    ih.swapping(str);
    ih.changeToUppercase(str);
    std::cout << str << std::endl;
    ih.setParameters(str);
    std::cout << "Horizontal: " << ih.getHorizontalParameter() << std::endl;
    std::cout << "Vertical: " << ih.getVerticalParameter() << std::endl;


    /*std::string str1 = "110";
    std::cout << std::stoi(str1,nullptr, 2) << std::endl;*/

    return 0;
}
