#include "Open.hpp"

std::deque<std::shared_ptr<Stream :: Stream>> Open::Open2(char* argv[], int argc){

    if (argc < 5){
        throw NotWay();
    }

    bool help_input = (string(argv[1]) == "-h");

    if ((help_input) && (argc < 6)){
        throw NotWay();
    }

    std::deque<std::shared_ptr<Stream :: Stream>>  answer;

    for (int i = 2 + static_cast<int>(help_input); i < argc; ++i){
        std::string way = string(argv[i]);
        std::string mode = "IN";

        if(i == 2 + static_cast<int>(help_input) + 1){

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