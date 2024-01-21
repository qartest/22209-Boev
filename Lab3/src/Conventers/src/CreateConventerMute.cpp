#include <Conventers/CreateConventerMute.hpp>
#include "MuteConventer.hpp"

namespace Conventers
{
    IConventerPtr CreateMute :: create_conventer(std::vector<int> params){
        return std::make_shared<MuteConventer>(params);
    }
}