#include "Wav_Header.hpp"

namespace WavHeader{

    bool NotMono(wav_hdr wav_header){
        if(wav_header.AudioFormat == 1){
            return false;
        }
        return true;
    }

    bool NotPCM(wav_hdr wav_header){
        if(wav_header.AudioFormat == 1){
            return false;
        }
        return true;
    }

    bool Not16B(wav_hdr wav_header){
        if(wav_header.bitsPerSample == 16){
            return false;
        }
        return true;
    }

    bool Not44100G(wav_hdr wav_header){
        if(wav_header.SamplesPerSec == 44100){
            return false;
        }
        return true;
    }

    bool NotWave(wav_hdr wav_header){
        if((wav_header.WAVE[0] == 'W') &&
        (wav_header.WAVE[1] == 'A') &&
        (wav_header.WAVE[2] == 'V') &&
        (wav_header.WAVE[3] == 'E')){
            return false;
        }
       return true;
    }

    ErrorsWav ReadInformationWav(std::string input){

        
        wav_hdr wav_header;
        
        std::fstream input_file(input, std::ios::in | std::ios::binary);

        input_file.read((char*)&wav_header, sizeof(wav_hdr));

        if (NotMono(wav_header)){
            return ErrorsWav :: NotMono;
        }

        if(NotPCM(wav_header)){
            return ErrorsWav :: NotPCM;
        }

        if (NotWave(wav_header)){
            return ErrorsWav :: NotWav;
        }
        return ErrorsWav :: Nothing;
    
    }
    OneSecond :: OneSecond ReadSecond(std::string input, int now_second){
        
        one_sample sample;

        std::fstream input_file(input, std::ios::in | std::ios::binary);

        input_file.seekg(44 + now_second * 88200, std::ios::beg);
        
        std::vector<one_sample> input_second(44100);

        for(int i = 0; i < 44100; ++i){
            input_file.read((char*)&sample, sizeof(one_sample));
            input_second[i] = sample;
        }        
        
        OneSecond :: OneSecond output;

        output.SetSecond(input_second);

        return output;    
    }

    void  WriteSecond(std::string output, OneSecond::OneSecond second, int now_second){

        std::fstream out_file(output, std::ios:: app | std::ios::binary);

        std::vector<one_sample> out = second.GiveData();

        for(int i = 0; i < out.size(); ++i){
            out_file.write((char*)&out[i], sizeof(one_sample));
        }
    }

    wav_hdr ReadAndWriteInfo(std::string output, std::string input){

        wav_hdr wav_header;

        std::fstream input_file(input, std::ios::in | std::ios::binary);

        input_file.read((char*)&wav_header, sizeof(wav_hdr));

        std::fstream out_file(output, std::ios:: out | std::ios::binary);

        out_file.write((char*)&wav_header, sizeof(wav_hdr));

        return wav_header;
    }

    wav_hdr Read(std::string input){
        wav_hdr wav_header;

        std::fstream input_file(input, std::ios::in | std::ios::binary);

        input_file.read((char*)&wav_header, sizeof(wav_hdr));
        return wav_header;
    }

    int GiveSeconds(wav_hdr input){
        if ((input.ChunkSize - 36) > 0){
            return ceil((input.ChunkSize - 36) / input.bytesPerSec);
        }
        return 0;
    }
}