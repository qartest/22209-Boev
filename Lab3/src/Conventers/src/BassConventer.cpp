#include "BassConventer.hpp"
#include <iostream>

namespace Conventers
{
BassConventer :: BassConventer() = default;

BassConventer :: BassConventer(int first, int second){
    time_begin_ = first;
    time_end_ = second;
}
void BassConventer :: Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files){
    if((now_second >= time_begin_) && (now_second < time_begin_)){
        int size_second = second.GiveSize();
        std::vector<one_sample> new_second(size_second);
        std::vector<one_sample> data_bass = second.GiveData();

        for(int i = 0; i < size_second; ++i){
            new_second[i] = (data_bass[i]) * 1.03;
        }

        second.SetSecond(new_second);
    }

}
}
