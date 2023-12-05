#include "BassConventer.hpp"
#include <iostream>

namespace Conventers
{
BassConventer :: BassConventer() = default;

BassConventer :: BassConventer(int first, int second){
    first_ = first;
    second_ = second;
}
void BassConventer :: Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::string> input_files){
    if((now_second >= first_) && (now_second < second_)){
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
