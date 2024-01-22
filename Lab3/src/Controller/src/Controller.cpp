#include "Controller.hpp"
#include <Conventers/CreateConventerBass.hpp>
#include <Conventers/CreateConventerMix.hpp>
#include <Conventers/CreateConventerMute.hpp>
#include <sstream>

namespace{
    void SetUpFactory(Factory::IFactoryPtr& factory){        
        factory -> Add("mix", std::make_shared<Conventers::CreateMix>());
        factory -> Add("mute", std::make_shared<Conventers::CreateMute>());
        factory -> Add("bass", std::make_shared<Conventers::CreateBass>());
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

void Controller :: ConfigParser(std::shared_ptr<Stream :: Stream> input){
    std::string s;

    std::vector<std::vector<std::string>> conventers_info;


    while(input -> getline(s, '\n')){

        std::vector<std::string> words;
        std::stringstream ss (s);
        std::string tmp;

        while(std::getline(ss, tmp, ' ')){
            words.push_back(tmp);
        }
        all_info.push_back(InfoConventer::InfoConventer(words));
    }
    
    Factory::IFactoryPtr factory  = Factory::create_factory();
    
    SetUpFactory(factory);

    for(int i = 0; i < all_info.size(); ++i){
        try{
            auto conventer = factory -> create(all_info[i].name, all_info[i].data2);
            if(conventer == nullptr){
                throw ConfigProblem();
            }
            conventers.push_back(conventer);
        }
        catch(ProgrammProblem& e){
             throw e;
        }
    }
}

int Controller :: MainBody(){
    try{
        ConfigParser(*(all_ways2.begin()));
    }
    catch(ConfigProblem& e){
        return e.what_index();
    }
    catch(ProgrammProblem& e){
        return e.what_index();
    }

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
    return 0;
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
    
    return MainBody();
}
