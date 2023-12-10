#pragma once
#include <string>
#include "../Game/game.hpp"
#include "../Interface/interface.hpp"


template<typename ... Ts>                                               
struct Overload : Ts ... { 
    using Ts::operator() ...;
};
template<class... Ts> Overload(Ts...) -> Overload<Ts...>;


class Controller{

    std::string name;

    std::vector<Errors> error;
    bool save_run;
    Mode mode;

    std::string name_of_root;
    int repeat_of_iteration;

    std::string out_file;

    private:
    void ShowError(Interface output);
    void Show(int amount, Game& game, Interface interface);
    

    public:
    void Run(Game& game);
    
    Controller() = default;
    Controller(call_input_data input);
    ~Controller() = default;
};


