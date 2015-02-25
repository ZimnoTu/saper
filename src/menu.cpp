#include "menu.h"
#include "game.h"

void Menu::displayMenu()
{
    std::cout << "Welcom to \"Minesweeper\"! \n";
    std::cout << "Choose level: \n";
    std::cout << "1. Beginer\n";
    std::cout << "2. Intermediate\n";
    std::cout << "3. Expert\n";
    std::cout << "4. Set your own field\n";

    std::cin >> chosenPosition;
        Game game;
    switch (chosenPosition)
    {
    case 1:
        game.setParameters(10, 10);
        game.play();
        break;
    case 2:
        game.setParameters(16, 16);
        game.play();
        break;
    case 3:
        game.setParameters(26, 26);
        game.play();
        break;
    case 4:
        std::cout << "trololo!\n";
        break;
    default:
        std::cout << "rrrrr\n";
        break;
    }


}
