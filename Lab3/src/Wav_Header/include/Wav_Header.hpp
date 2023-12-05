#pragma once
#include "ErrorsWav.hpp"
#include <OneSecond.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

typedef struct  WAV_HEADER
{
    /* RIFF Chunk Descriptor */
    unsigned char         RIFF[4];        // RIFF Header Magic header
    unsigned int        ChunkSize;      // RIFF Chunk Size
    unsigned char         WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    unsigned char         fmt[4];         // FMT header
    unsigned int         Subchunk1Size;  // Size of the fmt chunk
    unsigned short       AudioFormat;    // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM
    unsigned short        NumOfChan;      // Number of channels 1=Mono 2=Sterio
    unsigned int        SamplesPerSec;  // Sampling Frequency in Hz
    unsigned int        bytesPerSec;    // bytes per second
    unsigned short        blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    unsigned short      bitsPerSample;  // Number of bits per sample
    /* "data" sub-chunk */
    unsigned char         Subchunk2ID[4]; // "data"  string
    unsigned int        Subchunk2Size;  // Sampled data length
} wav_hdr;


namespace WavHeader{

    ErrorsWav ReadInformationWav(std::string input);

    bool NotMono(wav_hdr wav_header);
    bool NotPCM(wav_hdr wav_header);
    bool Not16B(wav_hdr wav_header);
    bool Not44100G(wav_hdr wav_header);
    bool NotWave(wav_hdr wav_header);

    OneSecond :: OneSecond ReadSecond(std::string input, int second);
    void WriteSecond(std::string output, OneSecond::OneSecond second, int now_second);

    wav_hdr Read(std::string input);
    wav_hdr ReadAndWriteInfo(std::string output, std::string  input);
    int GiveSeconds(wav_hdr input);

}