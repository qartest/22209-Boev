#pragma once

#include <Conventers/ICreateConventer.hpp>

namespace Conventers
{
class CreateMute : public ICreateConventer
{
public:
    CreateMute() = default;
    IConventerPtr create_conventer(int first, int second) override;
};
}