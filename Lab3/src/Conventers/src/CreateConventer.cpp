#include <Conventers/CreateConventer.hpp>

#include "MixConventer.hpp"
#include "MuteConventer.hpp"
#include "BassConventer.hpp"

namespace Conventers
{
IConventerPtr CreateConventer :: create_conventer(std::string name, int first, int second)
{
    if (name == "mix"){
        return std::make_shared<MixConventer>(first, second);
    }
    else if (name == "mute"){
        return std::make_shared<MuteConventer>(first, second);
    }
    else if (name == "bass"){
        return std::make_shared<BassConventer>(first, second);
    }
    return nullptr;

}
}