#pragma once
#include <string>

class InputHandler
{
public:
    bool checkMove(std::string &str);
    void eraseInvalidSigns(std::string &str);
    void swapping(std::string &str);
    bool areDigitsOnBothEnds(std::string str);
    bool isNumberOfAlphaAndDigitsGood (std::string str);
    std::string changeToUppercase(std::string &str);

    void setParameters(std::string checkedInput);
    int getHorizontalParameter();
    int getVerticalParameter();
    void setHorizontalParameter(std::string checkedInput);
    void setVerticalParameter(std::string checkedInput);

    void processInput(std::string &str);

private:
    int horizontalParameter;
    int verticalParameter;
};
