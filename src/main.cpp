#include <iostream>
#include <ctime>
#include "game.h"
#include "menu.h"

int main()
{
    srand(time(0));

    Menu menu;
    menu.displayMenu();

    /*std::string str = "aaaaabaa";
    std::cout << str.find('b',0) << std::endl;
    if(str.find('c', 0) <= str.length())
        std::cout << str.find('c',0) << std::endl;
    else
        std::cout << "c- nie wystepuje" << std::endl;

    std::cout << str.find("ab", 0) << std::endl;*/





    return 0;
}
