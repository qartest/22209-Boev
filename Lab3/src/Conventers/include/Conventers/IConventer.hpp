#pragma once 
#include <OneSecond.hpp>
#include <deque>
#include <string>

namespace Conventers
{
struct IConventer
{   
    virtual ~IConventer() = default;
    virtual void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::string> input_files) = 0;
};

}