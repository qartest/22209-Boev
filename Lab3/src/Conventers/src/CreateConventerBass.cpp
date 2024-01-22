#include <Conventers/CreateConventerBass.hpp>
#include "BassConventer.hpp"


namespace Conventers
{
    IConventerPtr CreateBass :: create_conventer(std::vector<int> params){
        return std::make_shared<BassConventer>(std::move(params));
    }
}
