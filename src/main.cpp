#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "menu.h"


int main()
{
    srand(time(0));

    /*Game game;
    game.play();*/
    Menu menu;
    menu.displayMenu();

    return 0;
}
