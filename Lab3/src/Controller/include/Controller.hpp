#pragma once
#include <Open.hpp>
#include <Wav_Header.hpp>
#include <Factory/FactoryCreator.hpp>
#include <Factory/IFactory.hpp>


class Controller
{   

private:
    bool help_index;
    std::string config;
    std::deque<std::string> all_ways;
    std::vector<Conventers::IConventerPtr> conventers;

    void CheckHelp();
    void CheckWav();

    void ConfigParser(std::string config);
    std::vector<std::string> StringParser(std::string input);
    void MakeConveters(std::vector<std::vector<std::string>> input);

    void MainBody();

public:
    Controller();
    ~Controller() = default;
    int Start(int argc, char* argv[]);

};