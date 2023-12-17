#pragma once 
#include <OneSecond.hpp>
#include <stream.hpp>
#include <deque>
#include <string>
#include <memory>


namespace Conventers
{
struct IConventer
{   
    virtual ~IConventer() = default;
    virtual void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files) = 0;
};

}