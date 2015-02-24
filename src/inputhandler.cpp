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

std::string InputHandler::eraseInvalidSigns(std::string &str)
{
    std::string tmpString = str;
    tmpString.erase(remove_if(tmpString.begin(), tmpString.end(), isNotAlphaOrDigit),
                     tmpString.end());
    return tmpString;
}

bool InputHandler::areDigitsOnBothEnds(std::string str)
{
    if (isdigit(str.front()) && isdigit(str.back()))
        return true;
    return false;
}

std::string InputHandler::swapping(std::string str) /////BOŻE JAK FOKA PŁACZE!
{
    std::string tmpString = str;
    std::string tmpString2;
    std::rotate(tmpString.begin(),
                    std::find_if(tmpString.begin(), tmpString.end(), isalpha),
                    tmpString.end());
    tmpString2 = tmpString;
    return tmpString2;
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

std::string InputHandler::prepareInputToRead( std::string &str)
{
    std::string tmpString;
    tmpString = eraseInvalidSigns(str);
    if(!isNumberOfAlphaAndDigitsGood(tmpString))
        return "0";
    if(areDigitsOnBothEnds(tmpString))
        return "0";
    tmpString = swapping(tmpString);
    tmpString = changeToUppercase(tmpString);
    return tmpString;
}
std::string InputHandler::changeToUppercase( std::string &str)
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
    verticalParameter = stoi(substring) - 1;
}

std::string InputHandler::processInput(std::string &str)
{
    std::string processedInput;
    processedInput = prepareInputToRead(str);
    if(processedInput != "0")
        setParameters(processedInput);
    return processedInput;
}
