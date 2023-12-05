#pragma once
#include <Errors.hpp>
#include <vector>
#include <deque>
#include <fstream>

namespace Open
{
    std::deque<std::string> Open(char* argv[], int argc);
}