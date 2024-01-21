#include "BassConventer.hpp"
#include <iostream>
#include <variant>

namespace Conventers
{
BassConventer :: BassConventer() = default;

BassConventer :: BassConventer(std::vector<int> params){
    time_begin_ = params[0];
    time_end_ = params[1];
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
