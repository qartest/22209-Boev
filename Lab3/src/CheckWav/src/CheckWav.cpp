#include "CheckWav.hpp"

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

    ErrorsWav ReadInformationWav(wav_hdr wav_header){

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
}