#pragma once

#include <memory>

namespace Factory
{
struct IFactory;
using IFactoryPtr = std::shared_ptr<IFactory>;
}