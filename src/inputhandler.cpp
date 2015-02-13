#include <cctype>
#include <algorithm>
#include "inputhandler.h"

void InputHandler::spaceEraser(std::string &str)
{
    str.erase(remove_if(str.begin(), str.end(), isspace),
              str.end());
}

void InputHandler::needSwap(std::string &str)
{
    if (isdigit(str[0]) && isalpha(str[1]) && !isdigit(str[2]))
        std::swap(str[0], str[1]);
}
bool isAlphaOrDigitInWrongPlace (std::string &str)
{
    return !isalpha(str[0]) || !isdigit(str[1]);
}

bool InputHandler::checkMove(std::string str)
{
    spaceEraser(str);
    //erase white spaces+, find 1 alpha, find max 2 digits, swap characters if needed, check


    needSwap(str);
    if (isAlphaOrDigitInWrongPlace(str))
        return false;
    for (int i = 2; i<str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}
