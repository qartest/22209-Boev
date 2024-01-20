#include <Conventers/CreateConventerMix.hpp>
#include "MixConventer.hpp"

namespace Conventers
{
    IConventerPtr CreateMix :: create_conventer(int first, int second){
        return std::make_shared<MixConventer>(first, second);
    }
}