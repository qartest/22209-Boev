#pragma once

#include <memory>
#include <vector>
#include <algorithm> 
#include <bitset>
#include "../Functions/Function.hpp"


enum class State
{
    Dead,
    Alive,
};

class Field
{
public:
    Field() = default;
    Field(int size);
    State getState(int x, int y);
    void setCell(int x, int y, State state);
    int getSizeofside();

private:
    int size_of_side;
    std::vector<State> field;
};

class Game{

public:

    void RecountMap();
    void RecountSize(int side);

    int GiveSizeX();
    int GiveSizeY();

    void TakeCell(int place, State state);
    bool LiveOfCell(int x, int y);

    int GiveSizeRulers();
    bool GiveSurval(int number);
    bool GiveBorn(int number);
    void TakeSurval(int number);
    void TakeBorn(int number);

    Game() = default;
    Game(int size);
    ~Game() = default;


private:

    Field my_field;

    std::bitset <8> rule_s;
    std::bitset <8> rule_b;

    int size_x_;
    int size_y_;

    bool CheckOnePixel(int coord_x, int coord_y);

};