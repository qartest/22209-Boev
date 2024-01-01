#pragma once

#include <Conventers/Fwd.hpp>

#include <string>

namespace Conventers
{
struct CreateConventer
{
    CreateConventer() = default;
    IConventerPtr create_conventer(std::string name, int first, int second);
};

}

