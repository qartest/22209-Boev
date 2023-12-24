#pragma once
#include <fstream>
#include <string>
#include <memory>
#include <wav_hdr.hpp>
#include <OneSecond.hpp>

namespace Stream{
class Stream
{
private:
    std::fstream data;
    wav_hdr info;

public:

    Stream() = default;
    Stream(std::string input, std::string mode);
    Stream(Stream&& vb);
    Stream& operator=(Stream&& vb);
    bool CheckData();
    virtual ~Stream() = default;

    wav_hdr Read();
    bool getline(std::string& input, char delitel);

    OneSecond :: OneSecond ReadSecond(int now_second);
    void WriteSecond(OneSecond::OneSecond second);
    wav_hdr WriteInfo(std::shared_ptr<Stream> input);
};

};
