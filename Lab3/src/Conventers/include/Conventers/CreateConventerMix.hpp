#pragma once

#include <Conventers/ICreateConventer.hpp>

namespace Conventers
{
class CreateMix : public ICreateConventer
{
public:
    CreateMix() = default;
    IConventerPtr create_conventer(std::vector<int> params) override;
};
}