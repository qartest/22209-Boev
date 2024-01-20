#include <Conventers/CreateConventerMute.hpp>
#include "MuteConventer.hpp"

namespace Conventers
{
    IConventerPtr CreateMute :: create_conventer(int first, int second){
        return std::make_shared<MuteConventer>(first, second);
    }
}