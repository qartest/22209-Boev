#pragma once

#include <Factory/IFactory.hpp>

namespace Factory
{
class Factory : public IFactory
{
public:
    Factory() = default;
    Conventers :: IConventerPtr create(std::string name, int fisrt, int second) override;
};
}