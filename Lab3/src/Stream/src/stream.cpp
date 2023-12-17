#include "stream.hpp"

namespace Stream{
    Stream :: Stream(std::string input, std::string mode){
        if(mode == "IN"){
            data = std::fstream (input, std::ios::binary | std::ios::in);
        }
        else{
            data = std::fstream (input, std::ios::binary | std::ios::out);
        }
    }

    Stream :: Stream(Stream&& vb){
        data = (std::move(vb.data)); 
        info = vb.info;
    }
    bool Stream :: CheckData(){
        return data.is_open();
    }
    
    Stream& Stream :: operator=(Stream&& vb){
        if(this != &vb){
            data = std::move(vb.data);
            info = vb.info;
        }
        return *this;
    }
    wav_hdr Stream :: Read(){
        data.seekg(0, std::ios::beg);
        wav_hdr wav_header;
        data.read((char*)&wav_header, sizeof(wav_hdr));
        info = wav_header;
        return wav_header;
    }

    bool Stream :: getline(std::string& input, char delitel){
        if(std::getline(data, input, delitel)){
            return true;
        }
        return false;
    }

    OneSecond :: OneSecond Stream ::ReadSecond(int now_second){
        wav_hdr input = info;
        unsigned int max_second = wav_hdr_functions :: GiveSeconds(input);
        if(now_second < max_second){
            one_sample sample;
            // data.seekg(0, std::ios::beg);
            data.seekg(44 + now_second * 88200, std::ios::beg);

            std::vector<one_sample> input_second(44100);

            for(int i = 0; i < 44100; ++i){
                data.read((char*)&sample, sizeof(one_sample));
                input_second[i] = sample;
            }

            OneSecond :: OneSecond output;

            output.SetSecond(input_second);
            return output;
        }
        return OneSecond :: OneSecond();
    }

    void Stream :: WriteSecond(OneSecond::OneSecond second){

        std::vector<one_sample> out = second.GiveData();

        for(int i = 0; i < out.size(); ++i){
            data.write((char*)&out[i], sizeof(one_sample));
        }
    }

    wav_hdr Stream :: WriteInfo(std::shared_ptr<Stream> input){

        wav_hdr wav_header = input -> Read();

        data.write((char*)&wav_header, sizeof(wav_hdr));

        return wav_header;
    }

};
