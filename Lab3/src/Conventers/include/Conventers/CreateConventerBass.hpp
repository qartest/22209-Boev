#pragma once
#include <Conventers/ICreateConventer.hpp>

namespace Conventers
{
class CreateBass : public ICreateConventer
{
public:
    CreateBass() = default;
    IConventerPtr create_conventer(std::vector<int> params) override;
};
}