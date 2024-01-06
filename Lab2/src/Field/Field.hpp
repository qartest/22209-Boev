#pragma once
#include <vector>
#include "../EnumClasses/State.hpp"


class Field
{
public:
    Field() = default;
    Field(int size);
    State getState(int x, int y) const;
    void setCell(int x, int y, State state);
    int getSizeofside() const;

private:
    int size_of_side;
    std::vector<State> field;
};