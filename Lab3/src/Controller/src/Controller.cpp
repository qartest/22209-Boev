#include "Controller.hpp"
#include <sstream>

namespace{
    bool CheckCommand(std::vector<std::string>& input){
        if (((input[0] == "mix") || input[0] == "mute") || input[0] == "bass"){
            if (input[1][0] == '$'){
                input[1] = input[1].substr(1);
            }
            if((std::isdigit(input[1][0])) && (std::isdigit(input[2][0]))){
                return true;
            }
        }
        return false;
    }
}

bool Controller :: CheckHelp(){
    if (!(*(--all_ways2.end())) -> CheckData()){
        all_ways2.pop_back();
        return true;
    }
    return false;
}
 
void Controller :: CheckWav(){
    for (auto i = all_ways2.end() - 1; i != all_ways2.begin() + 1; --i){

        ErrorsWav answer = WavHeader::ReadInformationWav((*i) -> Read());
        switch (answer){
            case ErrorsWav :: NotMono:
                throw NotMono();
            break;

            case ErrorsWav :: NotPCM:
                throw NotPCM();
            break;
            
            case ErrorsWav :: Not16B:
                throw Not16B();
            break;

            case ErrorsWav :: Not44100G:
                throw Not44100G();
            break;

            case ErrorsWav :: NotWav:
                throw NotWav();
            break;

            case ErrorsWav :: Nothing:
            break;

            default:
            break;
        }
    }
}

void Controller :: MakeConveters(std::vector<std::vector<std::string>> input){
    Factory::IFactoryPtr factory  = Factory::create_factory();

    for (int i = 0; i < input.size(); ++i){
        conventers.push_back( factory -> create(input[i][0], std::stoi(input[i][1]), std::stoi(input[i][2])));
    }
    
}

std::vector<std::string> Controller :: StringParser(std::string input){
    std::vector<std::string> words;
    std::stringstream ss (input);
    std::string tmp;

    while(std::getline(ss, tmp, ' ')){
        words.push_back(tmp);
    }

    if (words.size() == 3){
        if (CheckCommand(words)){
            return words;
        }
    }
    return std::vector<std::string>();
}


void Controller :: ConfigParser(std::shared_ptr<Stream :: Stream> input){
    std::string s;

    std::vector<std::vector<std::string>> conventers_info;


    while(input -> getline(s, '\n')){
        std::vector<std::string> one_conventer = StringParser(s);

        if(one_conventer != std::vector<std::string>()){
            conventers_info.push_back(one_conventer);
        }
    }

    MakeConveters(conventers_info);

}

void Controller :: MainBody(){

    ConfigParser(*(all_ways2.begin()));
    all_ways2.pop_front();

    wav_hdr input_info = (*all_ways2.begin()) -> WriteInfo(*(++all_ways2.begin()));

    unsigned int all_seconds = wav_hdr_functions :: GiveSeconds(input_info);

    for (unsigned int i = 0; i < all_seconds; ++i){
        OneSecond :: OneSecond second = (*(++all_ways2.begin())) -> ReadSecond(i);
        for (auto j = conventers.begin(); j != conventers.end(); ++j){
            (*j) -> Do(i, second, all_ways2);
        }

        (*all_ways2.begin()) -> WriteSecond(second);
    }

}

int Controller :: Start(int argc, char* argv[])
{   
    
    try{
        all_ways2 = Open::Open2(argv, argc);
        
    }
    catch(BadWay& e){
        return e.what_index();
    }
    catch(NotWay& e){
        return e.what_index();
    }

    if(CheckHelp()){
        std::cout << "It is help for you" << std::endl;
    }

    try{
        CheckWav();
    }
    catch(NotWav& e){
        return e.what_index();
    }
    catch(Not44100G& e){
        return e.what_index();
    }
    catch(NotPCM& e){
        return e.what_index();
    }
    catch(NotMono& e){
        return e.what_index();
    }
    
    MainBody();

    return 0;
}
