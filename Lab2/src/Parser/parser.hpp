#pragma once
#include "../Game/game.hpp"
#include "../Example/example.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>


namespace Parser{
    call_input_data ParsingInput(int argc, char** agrv);
}