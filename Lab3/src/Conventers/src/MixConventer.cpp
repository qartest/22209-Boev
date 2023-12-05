#include "MixConventer.hpp"
#include <Wav_Header.hpp>
#include <iostream>

namespace Conventers
{
MixConventer :: MixConventer() = default;

MixConventer :: MixConventer(int first, int second){
    first_ = first;
    second_ = second;
}
void MixConventer :: Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::string> input_files){
        if((now_second >= second_) && (first_ < input_files.size())){
            
            wav_hdr second_file = WavHeader :: Read(input_files[first_]);

            if (now_second < WavHeader::GiveSeconds(second_file)){
                int size_second = second.GiveSize();

                std::vector<one_sample> new_second(size_second);

                std::vector<one_sample> data_mix_1 = second.GiveData();
                std::vector<one_sample> data_mix_2 = WavHeader :: ReadSecond(input_files[first_], now_second).GiveData();
                for(int i = 0; i < size_second; ++i){
                    new_second[i] = ((data_mix_1[i] + data_mix_2[i]));
                }       
                second.SetSecond(new_second);
            }

    }
}
}