#pragma once
#include <string>
#include "../Interface/interface.hpp"

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

    

    public:
    void Run(Game& game);
    
    Controller() = default;
    Controller(call_input_data input);
    ~Controller() = default;
};


