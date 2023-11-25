#pragma once

#include <memory>
#include <vector>
#include <algorithm> 
#include <bitset>
#include "../Functions/Function.hpp"

class Game{

public:
    std::vector<char> GiveMap();
    void GiveZeroMap(int number);
    void RecountMap();
    void RecountSize(int x, int y);

    int GiveSizeX();
    int GiveSizeY();

    void TakeCell(int place);
    bool LiveOfCell(int number);

    int GiveSizeRulers();
    bool GiveSurval(int number);
    bool GiveBorn(int number);
    void TakeSurval(int number);
    void TakeBorn(int number);

    Game() = default;
    Game(int size_x, int size_y);
    ~Game() = default;


private:

    std::vector<char> map_;

    std::bitset <8> rule_s;
    std::bitset <8> rule_b;

    int size_x_;
    int size_y_;

    bool CheckOnePixel(int coord_x, int coord_y);

};