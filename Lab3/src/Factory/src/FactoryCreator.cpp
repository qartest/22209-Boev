#include <Factory/FactoryCreator.hpp>

#include "Factory.hpp"

namespace Factory
{
    IFactoryPtr create_factory(){
        return std::make_shared<Factory>();
    }
}