#pragma once

#include <Conventers/ICreateConventer.hpp>

namespace Conventers
{
class CreateMix : public ICreateConventer
{
public:
    CreateMix() = default;
    IConventerPtr create_conventer(int first, int second) override;
};
}