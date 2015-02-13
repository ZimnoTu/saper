#pragma once
#include <string>

class InputHandler
{
public:
    bool checkMove(std::string str);
    void spaceEraser(std::string &str);

    void needSwap(std::string &str);
};
