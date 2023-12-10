#pragma once
#include <bitset>
#include "../Field/Field.hpp"

struct call_input_data{
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
    
};