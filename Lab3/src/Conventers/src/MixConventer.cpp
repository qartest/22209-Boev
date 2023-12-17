#include "MixConventer.hpp"
#include <iostream>

namespace Conventers
{
MixConventer :: MixConventer() = default;

MixConventer :: MixConventer(int first, int second){
    input_digit_ = first;
    time_begin_ = second;
}
void MixConventer :: Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files){
        if((now_second >= time_begin_) && (input_digit_ < input_files.size())){
            
            OneSecond :: OneSecond second_mix_2 = input_files[input_digit_]->ReadSecond(now_second);

            if (second_mix_2.GiveData().size() != 0){

                int size_second = second.GiveSize();

                std::vector<one_sample> new_second(size_second);

                std::vector<one_sample> data_mix_1 = second.GiveData();
                std::vector<one_sample> data_mix_2 = second_mix_2.GiveData();
                for(int i = 0; i < size_second; ++i){
                    new_second[i] = ((data_mix_1[i] + data_mix_2[i]));
                }       
                second.SetSecond(new_second);
            }

    }
}
}