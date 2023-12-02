#include "controller.hpp"
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <filesystem>
#include <variant>

namespace{

void  Write(std::ofstream output, std::string name, Game& game){

    Field field = game.GiveField();
    int size = field.getSizeofside();

    output << "#Life 1.06" << std::endl;
    output << "#N " << name << std::endl;
    output << "#F " << std::to_string(size) << std::endl;
    output << "#R B";
    int size_rule = game.GiveSizeRulers();
    for (int i = 0; i < size_rule; ++i){
            if (game.GiveSurval(i)){
                output << std::to_string(i);
        }
    }
    output << "/S";
    for (int i = 0; i < size_rule; ++i){
        if (game.GiveBorn(i)){
            output << std::to_string(i);
        }
    }
    output << std::endl;



    for(int y = 0; y < size; ++y){
        for (int x = 0; x < size; ++x){
            if (field.getState(x, y) == State :: Alive){
                output << std::to_string(x) << " " << std::to_string(y) << std::endl;
            }
        }
    }
}

void Save(std::string name, Game& game, std::string name_of_root){

    std::string full_name_directory = name_of_root + "/" +"Saves";
    std::string full_name_file = full_name_directory + "/" + name + ".txt";
    auto result = std::filesystem::create_directory(full_name_directory);
    if (name[0] != '/'){
        Write(std::ofstream (full_name_file),name, game);
    }
    else{
        srand((unsigned) time(NULL));
        std::string rand_name = std::to_string(rand() % 100000);
        std::string my_name = "Your_save" + rand_name;
        if(std::ofstream(name)){
            Write(std::ofstream (name),my_name, game);
        }
        else{
            std::cout << "I can't save your file in your place... Sorry, but I save its in directory Saves!!!" << std::endl;
            Write(std::ofstream(full_name_file), my_name, game);
            std::cout << "Your name - " + my_name << std::endl;

        }
    }
}

}

struct MainBuilder
{
    bool operator()(const VExit& exit){
        return false;
    }

    bool operator()(const VDump& dump){
        Save(dump.out, dump.game, dump.name_of_root);
        return true;
    }

    bool operator()(const VBad& bad){
        std::cout << "I don't know what you mean. Please, repeat" << std::endl;
        return true;
    }

    bool operator()(VTick& tick){
        return true;
    }

    bool operator()(const VHelp& help){
        return true;
    }

    bool operator()(VSize& size){
        return true;
    }
};

Controller :: Controller(call_input_data input){
    name = input.name;
    repeat_of_iteration = input.repeat_of_iteration;
    mode = input.mode;
    save_run = input.save_run;
    error = input.errors;
    out_file = input.output_name;
}

void Controller :: ShowError(Interface output){
    if (error.size() > 0){
        output.ShowErrors(error);
        error.clear();
    }

}

void Controller :: Run(Game& game){


    Interface first;
    ShowError(first);

    if (mode == Mode::Offline){
        Save(name, game, name_of_root);
        first.ShowSave();
    }
    else{
        std::cout << "Hello!" << std::endl;
        bool run_game = true;
        while(run_game){
            auto gp = first.Input_Analysis(game, name_of_root);
            run_game = std::visit(MainBuilder{}, gp);
        }
    }
}





