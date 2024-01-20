#pragma once

#include <Conventers/ICreateConventer.hpp>
#include <Conventers/Fwd.hpp>
namespace Conventers
{
class CreateBass : public ICreateConventer
{
public:
    CreateBass() = default;
    IConventerPtr create_conventer(int first, int second) override;
};
}