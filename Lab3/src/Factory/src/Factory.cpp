#include "Factory.hpp"
#include <Conventers/CreateConventer.hpp>
#include <iostream>

namespace Factory
{

Conventers :: IConventerPtr  Factory :: create(std::string name, int first, int second){
    return Conventers::create_conventer(name, first, second);
}
}
