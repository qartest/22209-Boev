#pragma once
#include <memory>
#include <vector>
#include <algorithm> 
#include <bitset>
#include <string>
#include "EnumClasses.hpp"

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

typedef struct INPUT_DATA{
    std::bitset <8> rule_s;
    std::bitset <8> rule_b;

    Field my_field;

    int size_of_side;

    Mode mode;
    std::vector<Errors> errors;
    int repeat_of_iteration;

    std::string output_name;

    bool save_run;
    std::string name;

    std::string name_of_root;
    
}call_input_data;

class Game{

public:

    void RecountMap();
    void RecountSize(int side);

    int GiveSizeRulers();
    const Field GiveField() const;

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
