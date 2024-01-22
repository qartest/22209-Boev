#include "InfoConventer.hpp"
#include <string>

namespace{
    bool is_digit(std::string input){
        bool answer = false;
        for(int i = 0; i < input.size(); ++i){
            answer = true;
            if(!std::isdigit(input[i])){
                return false;
            }
        }
        return answer;
    }
}

namespace InfoConventer{
InfoConventer :: InfoConventer(std::vector<std::string> input){
    if(input.size() != 3){
        name = "bad";
    }
    else{
        if(input[0] == "mix"){
            bool check_mix = false;
            if(input[1][0] == '$'){
                input[1] = input[1].substr(1);
                check_mix = true;
                for(int i = 1; i < 3; ++i){
                    if(!is_digit(input[1])){
                        check_mix = false;
                    }
                    else{
                        data2.push_back(std::stoi(input[i]));
                    }
                }         
            }
            if(check_mix){
                name = "mix";
            }
            else{
                name = "bad";
            }
            
        }
        else{
            name = input[0];
            bool check_digit = true;
            for(int i = 1; i < 3; ++i){
                if(!is_digit(input[i])){
                    check_digit = false;
                }
                else{
                    data2.push_back(std::stoi(input[i]));
                }
            }
            if(!check_digit){
                name = "bad";
            }
        }
    }
}

InfoConventer :: InfoConventer(const InfoConventer& pb){
    data2 = pb.data2;
    name = pb.name;
}

InfoConventer :: InfoConventer(InfoConventer&& pb){
    data2 = std::move(pb.data2);
    name = std::move(pb.name);
}

InfoConventer& InfoConventer::operator=(const InfoConventer& pb){
    data2 = pb.data2;
    name = pb.name;
    return *this;
}

InfoConventer& InfoConventer::operator=(InfoConventer&& pb){
    data2 = std::move(pb.data2);
    name = std::move(pb.name);
    return *this;
}

}