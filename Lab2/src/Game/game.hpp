#pragma once
#include <memory>
#include <algorithm> 
#include <string>
#include "../CallInput/CallInput.hpp"



class Game{

public:

    void RecountMap();
    void RecountSize(int side);

    int GiveSizeRulers();
    const Field& GiveField() const;

    bool GiveSurval(int i);
    bool GiveBorn(int i);

    Game() = default;
    Game(call_input_data input);
    ~Game() = default;


private:

    Field my_field;

    std::bitset <8> rule_s;
    std::bitset <8> rule_b;

    bool CheckOnePixel(int coord_x, int coord_y);

};
