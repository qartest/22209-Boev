#include "Factory.hpp"
#include <iostream>

namespace Factory
{

Conventers :: IConventerPtr  Factory :: create(std::string name, std::vector<int> params){
    if(data.count(name) == 1){ // с contains НЕ РАБОТАЕТ почему-то
        return data[name]->create_conventer(params);
    }
    return nullptr;
}

void Factory :: Add(std::string name, Conventers :: ICreateConventerPtr create_object){
    data[name] = create_object;
}
}
