#pragma once
#include <string>

class InputHandler
{
public:
    std::string prepareInputToRead(std::string &str);
    std::string eraseInvalidSigns(std::string &str);
    std::string swapping(std::string str);
    bool areDigitsOnBothEnds(std::string str);
    bool isNumberOfAlphaAndDigitsGood (std::string str);
    std::string changeToUppercase(std::string &str);
    bool wantSetFlag(std::string str);
    std::string cutOffFlagInformation(std::string str);

    void setParameters(std::string checkedInput);
    int getHorizontalParameter();
    int getVerticalParameter();
    void setHorizontalParameter(std::string checkedInput);
    void setVerticalParameter(std::string checkedInput);

    std::string processInput(std::string &str);

private:
    int horizontalParameter;
    int verticalParameter;
};
