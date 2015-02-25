#include "menu.h"
#include "game.h"
#include <iostream>

void Menu::displayMenu()
{
    char exit = 'n';
    std::cout << "Welcom to \"Minesweeper\"! \n";
    while(exit != 'y' && exit != 'Y')
    {
        std::cout << "Choose level: \n";
        std::cout << "1. Beginer\n";
        std::cout << "2. Intermediate\n";
        std::cout << "3. Expert\n";
        std::cout << "4. Set your own field\n";

        std::cin >> chosenPosition;

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
            setOwnField();
            game.play();
            break;
        default:
            std::cout << "Invalid choise!\nSelect level: ";
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
        }
        std::cout << "Do you want to quit? Y/N ?\n";
        std::cin >> exit;
    }
    std::cout << "wow wow! such good game!\n";
}

void Menu::setOwnField()
{
    unsigned int horizontal = 0, vertical = 0;

    std::cout << "Set horizontal parameter:\t";
    std::cin >> horizontal;
    while(!std::cin.good() || horizontal > 26)
    {
        std::cout << "\tWrong parameters!\n\tMax horizontal length = 26\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> horizontal;
    }

    std::cout << "Set vertical parameter:\t";
    std::cin >> vertical;
    while(!std::cin.good() || vertical > 99)
    {
        std::cout << "\tWrong parameters!\n\tMax vertical length = 99\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> vertical;
    }

    game.setParameters(horizontal, vertical);
}
