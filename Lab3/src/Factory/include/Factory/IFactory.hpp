#pragma once
#include <Conventers/Fwd.hpp>
#include <string>


namespace Factory
{
struct IFactory
{
    virtual ~IFactory() = default;
    virtual Conventers :: IConventerPtr create(std::string name, int first, int second) = 0;
    
}; 
}