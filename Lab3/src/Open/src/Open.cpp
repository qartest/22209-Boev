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