#include <cctype>
#include "inputhandler.h"

bool InputHandler::checkMove(std::string str)
{
    if (!isalpha(str[0]) || !isdigit(str[1]))
        return false;
    for(int i = 2; i<str.length(); i++)
        if (!isdigit(str[i]))
            return false;
    return true;
}
