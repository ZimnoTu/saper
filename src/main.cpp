#include <iostream>
#include <cstdlib>
#include <ctime>
#include "minefield.h"
#include "minefielddrawer.h"
#include "inputhandler.h"
#include "game.h"

int main()
{
    srand(time(0));

    /*MineField mf(26,10);
    MineFieldDrawer md;
    mf.putRandomBombs();
    mf.checkIfbombIsAround();
    md.drawField(mf);*/

   /* Game game(26,10);
    game.startGame();
    std::string s1 ("B2");
    std::string s2 ("2c");
    std::string s3 ("10a");
    std::string s4 ("1r");
    std::string s5 ("10g");
    game.makeMove(s1);
    game.makeMove(s2);
    /*game.makeMove(s3);
    game.makeMove(s4);*/

   // game.draw();

    Game game;
    game.play();

    /*InputHandler ih;
    std::string str ("3c");
    std::cout << str << std::endl;
    ih.swapping(str);
    ih.changeToUppercase(str);
    std::cout << str << std::endl;
    ih.setParameters(str);
    std::cout << "Horizontal: " << ih.getHorizontalParameter() << std::endl;
    std::cout << "Vertical: " << ih.getVerticalParameter() << std::endl;

    std::cout << str << std::endl;*/

    return 0;
}
