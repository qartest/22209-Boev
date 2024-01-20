#pragma once
#include <Factory/IFactory.hpp>
#include <map>

namespace Factory
{
class Factory : public IFactory
{
private:
    std::map<std::string, Conventers :: ICreateConventerPtr> data;

public:
    Factory() = default;
    Conventers :: IConventerPtr create(std::string name, std::vector<std::string> params) override;
    void Add(std::string name, Conventers :: ICreateConventerPtr create_object) override;
};
}