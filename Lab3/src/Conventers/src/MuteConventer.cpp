#include "MuteConventer.hpp"
#include <iostream>

namespace Conventers
{
MuteConventer :: MuteConventer(int first, int second){
    time_begin_ = first;
    time_end_ = second;
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
