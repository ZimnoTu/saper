#pragma once

enum class StateOFField : char {covered, uncovered, flag };

struct SmallField
{
    int value;
    StateOFField state;
    SmallField();
};
