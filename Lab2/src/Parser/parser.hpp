#pragma once
#include "../CallInput/CallInput.hpp"
#include "../Example/example.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

enum class StateOfCall{
    NumberOfRepeat2Words,
    NumberOfRepeat1Words,
    OutputFile1Word,
    OutputFile2Word,
    InputFile,
    Bad,
};


namespace Parser{
    call_input_data ParsingInput(int argc, char** agrv);
}