#pragma once
#include <Conventers/Fwd.hpp>
#include <memory>
#include <string>


namespace Conventers
{
struct ICreateConventer
{
    ICreateConventer() = default;
    virtual IConventerPtr create_conventer(std::vector<int> params) = 0;
};

using ICreateConventerPtr = std::shared_ptr<ICreateConventer>;
}

