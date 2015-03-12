#include "menu.h"
#include "game.h"
#include <iostream>
#include <thread>

void Menu::displayMenu()
{
    char contiune = 'y';
    std::cout << "Welcome to \"Minesweeper\"! \n";
    while(contiune != 'n' && contiune != 'N')
    {
        game.eraseMinefield();
        std::cout << "Choose level: \n";
        std::cout << "1. Beginer\n";
        std::cout << "2. Intermediate\n";
        std::cout << "3. Expert\n";
        std::cout << "4. Set your own field\n";
        std::cout << "5. Exit\n";

        std::cin >> chosenPosition;

        switch (chosenPosition)
        {
        case 1:
            playBeginerLvl();
            break;

        case 2:
            playIntermediateLvl();
            break;

        case 3:
            playExpertLvl();
            break;

        case 4:
            playOwnLvl();
            break;

        case 5:
            contiune = 'n';
            break;

        default:
            selectedInvalidOption();
            continue;

        }
        if(chosenPosition != 5)
        {
            std::cout << "Would you like to continue? Y/N ?\n";
            std::cin >> contiune;
        }
    }
    std::cout << "wow wow! such good game!\n";
}

void Menu::setOwnField()
{
    unsigned int horizontal = 0, vertical = 0;

    std::cout << "Set horizontal parameter: ";
    std::cin >> horizontal;
    while(!std::cin.good() || horizontal > game.getMaxHorizontalSize())
    {
        std::cout << "\tWrong parameters!\n\tMax horizontal length = 26\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> horizontal;
    }

    std::cout << "Set vertical parameter: ";
    std::cin >> vertical;
    while(!std::cin.good() || vertical > game.getMaxVerticalSize())
    {
        std::cout << "\tWrong parameters!\n\tMax vertical length = 99\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cin >> vertical;
    }

    game.setParameters(horizontal, vertical);
}

void Menu::playBeginerLvl()
{
    game.setParameters(10, 10);
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    game.play();
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop-start).count();
    std::cout << "Time: " << duration << " sec"<< std::endl;
}

void Menu::playIntermediateLvl()
{
    game.setParameters(16, 16);
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    game.play();
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop-start).count();
    std::cout << "Time: " << duration << " sec"<< std::endl;
}

void Menu::playExpertLvl()
{
    game.setParameters(26, 26);
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    game.play();
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop-start).count();
    std::cout << "Time: " << duration << " sec"<< std::endl;
}

void Menu::playOwnLvl()
{
    setOwnField();
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    game.play();
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop-start).count();
    std::cout << "Time: " << duration << " sec"<< std::endl;
}

void Menu::selectedInvalidOption()
{
    std::cout << "Invalid choise!\nSelect level: ";
    std::cin.clear();
    std::cin.ignore(100, '\n');
}
