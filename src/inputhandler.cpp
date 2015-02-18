#include <cctype>
#include <algorithm>
#include <iostream>
#include <string>
#include "inputhandler.h"

auto isNotAlphaOrDigit = [](char &s) //teraz funkcja jest na stosie a nie na stercie
{
    if(!std::isalnum(s))
        return true;
    return false;
};

void InputHandler::eraseInvalidSigns(std::string &str)
{
    str.erase(remove_if(str.begin(), str.end(), isNotAlphaOrDigit),
              str.end());
}

bool InputHandler::areDigitsOnBothEnds(std::string str)
{
    if (isdigit(str.front()) && isdigit(str.back()))
        return true;
    return false;
}

void InputHandler::swapping(std::string &str)
{
    std::rotate(str.begin(),
                std::find_if(str.begin(), str.end(), isalpha),
                str.end());
}

bool InputHandler::isNumberOfAlphaAndDigitsGood (std::string str)
{
    int digitCounter = count_if(str.begin(), str.end(), isdigit);
    int alphaCounter = count_if(str.begin(), str.end(), isalpha);
    if (digitCounter < 1 || digitCounter > 2)
        return false;
    if (alphaCounter != 1)
        return false;
    return true;
}

bool InputHandler::checkMove(std::string &str)
{
    eraseInvalidSigns(str);
    if(!isNumberOfAlphaAndDigitsGood(str))
        return false;
    if(areDigitsOnBothEnds(str))
        return false;
    swapping(str);
    return true;
}
std::string InputHandler::changeToUppercase(std::string &str)
{
    str.front() = toupper(str.front());
    return str;
}

void InputHandler::setParameters(std::string checkedInput)
{
    setHorizontalParameter(checkedInput);
    setVerticalParameter(checkedInput);
}

int InputHandler::getHorizontalParameter()
{
    return horizontalParameter;
}

int InputHandler::getVerticalParameter()
{
    return verticalParameter;
}
void InputHandler::setHorizontalParameter(std::string checkedInput)
{
    horizontalParameter = checkedInput.front()-65;
}

void InputHandler::setVerticalParameter(std::string checkedInput)
{
    std::string substring = checkedInput.substr(1,2);
    verticalParameter = stoi(substring)-1;
}

void InputHandler::processImput(std::string str)
{
    if(checkMove(str))
        setParameters(str);
}
