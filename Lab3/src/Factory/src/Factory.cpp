#include "Factory.hpp"
#include <iostream>

namespace Factory
{

Conventers :: IConventerPtr  Factory :: create(std::string name, std::vector<std::string> params){
    if(data.count(name) == 1){ // с contains НЕ РАБОТАЕТ почему-то
        return data[name].create_conventer(name, std::stoi(params[0]), std::stoi(params[1]));
    }
    return nullptr;
}

void Factory :: Add(std::string name, Conventers :: CreateConventer create_object){
    data[name] = create_object;
}
}
