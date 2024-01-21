#include <Conventers/CreateConventerMix.hpp>
#include "MixConventer.hpp"


namespace Conventers
{
    IConventerPtr CreateMix :: create_conventer(std::vector<int> params){
        return std::make_shared<MixConventer>( params);
    }
}