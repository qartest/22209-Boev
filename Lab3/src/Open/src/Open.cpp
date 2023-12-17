#include "Open.hpp"

std::deque<std::string> Open::Open(char* argv[], int argc){

    if (argc < 5){
        throw NotWay();
    }

    bool help_input = (argv[1] == "-h");

    if ((help_input) && (argc < 6)){
        throw NotWay();
    }

    std::deque<std::string> answer;

    for (int i = 2 + (int)help_input; i < argc; ++i){
        std::string way = string(argv[i]);
        
        if (!std::fstream(way).is_open()){
            throw BadWay();
        }
        answer.push_back(way);
    }

    if (help_input){
        answer.push_back("help");
    }

    return answer;
}

std::deque<std::shared_ptr<Stream :: Stream>> Open::Open2(char* argv[], int argc){

    if (argc < 5){
        throw NotWay();
    }

    bool help_input = (string(argv[1]) == "-h");

    if ((help_input) && (argc < 6)){
        throw NotWay();
    }

    std::deque<std::shared_ptr<Stream :: Stream>>  answer;

    for (int i = 2 + (int)help_input; i < argc; ++i){
        std::string way = string(argv[i]);
        std::string mode = "IN";

        if(i == 2 + (int)help_input + 1){
            mode = "OUT";
        }

        auto file = std::make_shared<Stream::Stream>(way, mode);
        if (!file->CheckData()){
            throw BadWay();
        }
        answer.emplace_back(file);
    }

    if (help_input){
        answer.emplace_back(std::make_shared<Stream::Stream>("help", "IN"));
    }

    return answer;
}