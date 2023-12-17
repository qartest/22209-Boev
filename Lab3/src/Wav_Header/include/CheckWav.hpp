#pragma once
#include "ErrorsWav.hpp"
#include <OneSecond.hpp>
#include <wav_hdr.hpp>
#include <stream.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <memory>


namespace WavHeader{

    ErrorsWav ReadInformationWav(wav_hdr wav_header);

    bool NotMono(wav_hdr wav_header);
    bool NotPCM(wav_hdr wav_header);
    bool Not16B(wav_hdr wav_header);
    bool Not44100G(wav_hdr wav_header);
    bool NotWave(wav_hdr wav_header);

}