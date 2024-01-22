#include "MuteConventer.hpp"
#include <Errors.hpp>
#include <iostream>

namespace Conventers
{
MuteConventer :: MuteConventer(std::vector<int> params){
    if(params.size() < 2){
        throw ProgrammProblem();
    }
    time_begin_ = params[0];
    time_end_ = params[1];
}
MuteConventer :: MuteConventer() = default;

void MuteConventer :: Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files){
    if((now_second >= time_begin_) && (now_second < time_end_)){
        int size_second = second.GiveSize();
        std::vector<one_sample> new_second(size_second);

        for(int i = 0; i < size_second; ++i){
            new_second[i] = 0;
        }

        second.SetSecond(new_second);
    }
}

}
