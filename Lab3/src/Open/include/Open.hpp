#pragma once
#include <stream.hpp>
#include <Errors.hpp>
#include <vector>
#include <deque>
#include <fstream>
#include <memory>

namespace Open
{
    std::deque<std::shared_ptr<Stream :: Stream>> Open2(char* argv[], int argc);
}