#include <Conventers/CreateConventerBass.hpp>
#include "BassConventer.hpp"


namespace Conventers
{
    IConventerPtr CreateBass :: create_conventer(int first, int second){
        return std::make_shared<BassConventer>(first, second);
    }
}
