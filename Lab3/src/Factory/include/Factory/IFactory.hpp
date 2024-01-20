#pragma once
#include <Conventers/Fwd.hpp>
#include <Conventers/ICreateConventer.hpp>
#include <string>


namespace Factory
{
struct IFactory
{   
    virtual ~IFactory() = default;
    virtual Conventers :: IConventerPtr create(std::string name, std::vector<std::string> params) = 0;
    virtual void Add(std::string name, Conventers :: ICreateConventerPtr create_object) = 0;
}; 
}