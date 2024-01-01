#pragma once
#include <memory>
#include <Open.hpp>
#include <CheckWav.hpp>
#include <Factory/FactoryCreator.hpp>
#include <Factory/IFactory.hpp>
#include <stream.hpp>
#include <InfoConventer.hpp>


class Controller
{   

private:

    std::string config;
    std::vector<Conventers::IConventerPtr> conventers;
    std::deque<std::shared_ptr<Stream :: Stream>> all_ways2;
    std::vector<InfoConventer :: InfoConventer> all_info;

    bool CheckHelp();
    void CheckWav();

    void ConfigParser(std::shared_ptr<Stream :: Stream> input);
    std::vector<std::string> StringParser(std::string input);
    void MakeConveters(std::vector<std::vector<std::string>> input);

    int  MainBody();

public:
    Controller() = default;
    ~Controller() = default;
    int Start(int argc, char* argv[]);

};