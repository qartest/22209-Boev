#include "controller.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <unistd.h>
#include <cstdlib>


Controller :: Controller() : Controller(100, 100){}

Controller :: Controller(int size_x, int size_y) : Game(size_x, size_y){
    name = " ";
    name_of_root = "";
    error = '\0';
    repeat_of_iteration = -1;
}


char* Controller::GiveMap(){
    return mapNew_;
}

void Controller :: ShowError(Interface output){
    output.PrintError(error);
    error = '\0';
}
int Controller :: GiveDigit(std::string int_string){
    int digit = -1;
    for(int j = 0; j < int_string.size(); ++j){
        if(isdigit(int_string[j])){
            digit = ((digit + (digit == -1)) * 10) + (int_string[j]- '0');
        }
        else{
            error = 'd';
            break;
        }
    }
    return digit;    
}

void Controller :: ReadCell(std::string input_line){
    int coords[] = {-1, -1};
    std::stringstream stream_digits(input_line);
    std :: string digit;
    for(int i = 0; i < 2; ++i){
        getline(stream_digits, digit, ' ');
        for(int j = 0; j < digit.size(); ++j){
            if(isdigit(digit[j])){
                coords[i] = ((coords[i] + (coords[i] == -1)) * 10) + (digit[j] - '0');
            }
            else{
                error = 'd';
                break;
            }
        }
    }
    
    if ((coords[0] > -1) && (coords[1] > -1)){
        int place_x = SaveStep(0, coords[0], size_x_);
        int place_y = SaveStep(0, coords[1], size_y_);
        mapNew_[NumberCell(place_x, place_y)] = 1;
    }    

}

void Controller :: ReadName(std::string input_line){

    for (int i = 0; i < input_line.size(); ++i){
        if (input_line[i] == 'N'){
            name = input_line.substr(3, input_line.size());
        }
        if (input_line[i] == 'B'){
            for(;i< input_line.size(); ++i){
                if (input_line[i] == '/'){
                    break;
                }
                if (isdigit(input_line[i])){
                    rule_b.push_back(input_line[i] - '0');
                }
            }
        }
        if (input_line[i] == 'S'){
            for(;i< input_line.size(); ++i){
                if (isdigit(input_line[i])){
                    rule_s.push_back(input_line[i] - '0');
                }
            }
        }
    } 
 
}


void Controller :: Read(std::fstream file_in){
    std::string input_line;

    while(getline(file_in, input_line, '\n')){
        if (input_line.size() == 0){
            break;
        }
        if(input_line[0] != '#'){
            ReadCell(input_line);
        }
        else{
            ReadName(input_line);
        }
    }
}

void Controller :: Open(std::string address){

    std::fstream file_in(address);
    if (file_in){
        Read(std::fstream (address));
    }
    else{
        error = 'f';
    }
}

void Controller :: Write(std::ofstream output, std::string name){
    output << "#Life 1.06" << std::endl;
    output << "#N " << name << std::endl;
    output << "#R B";
    for (int i = 0; i < rule_b.size(); ++i){
        output << std::to_string(rule_b[i]);
    }
    output << "/S";
    for (int i = 0; i < rule_s.size(); ++i){
        output << std::to_string(rule_s[i]);
    }
    output << std::endl;

    for(int y = 0; y < size_y_; ++y){
        for (int x = 0; x < size_x_; ++x){
            if (mapNew_[NumberCell(x, y)] == 1){
                output << std::to_string(x) << " " << std::to_string(y) << std::endl;
            }
        }
    }
}

void Controller :: Save(std::string name){

    std::string full_name_directory = name_of_root + "/" +"Saves";
    std::string full_name_file = full_name_directory + "/" + name + ".txt";
    auto result = std::filesystem::create_directory(full_name_directory);
    if (name[0] != '/'){
        Write(std::ofstream (full_name_file),name);
    }
    else{
        srand((unsigned) time(NULL));
        std::string rand_name = std::to_string(rand() % 100000);
        std::string my_name = "Your_save" + rand_name;
        if(std::ofstream(name)){
            Write(std::ofstream (name),my_name );
        }
        else{
            std::cout << "I can't save your file in your place... Sorry, but I save its in directory Saves!!!" << std::endl;
            Write(std::ofstream(full_name_file), my_name);
            std::cout << "Your name - " + my_name << std::endl;

        }
    }
}

void Controller :: SaveNameOfRoot(char* input){
    std::filesystem::path executablePath = std::filesystem::canonical(input);
    int count = 0;
    while (((*(--executablePath.end())).string() != "Lab2") && (count < 3)){
        executablePath = executablePath.parent_path();
        count++;
    }
     name_of_root = executablePath.string();
}

int Controller::PreRun(char * argv[], int argc){
    Interface first(size_x_, size_y_);
    for (int i = 1; i < argc; ++i){
        switch(Analiz(std::string(argv[i]))){
            case 1:
            ++i;
            if (i < argc){
                repeat_of_iteration = GiveDigit(std::string(argv[i]));
                if (repeat_of_iteration == -1){
                    error = 'r';
                }
            }
            else{
                error = 'c';
                i = argc;
            }
            break;

            case 2:
            ++i;
            if (i < argc){
                Save(std::string(argv[i]));
                first.PrintText('s');
                return 1;
            }
            else{
                error = 'c';
                i = argc;
            }
            break;

            case 3:
            Open(std::string(argv[i]));
            break;

            case 4:
            repeat_of_iteration = GiveDigit(std::string(argv[i]).substr(13));
            if (repeat_of_iteration == -1){
                error = 'r';
            }
            break;

            case 5:
            Save(std::string(argv[i]).substr(9));
            first.PrintText('s');
            return 1;
            break;

            case -1:
            error = 'c';
            i = argc;
            break;
        }
        ShowError(first);
        if (repeat_of_iteration != -1){
            for(int j = 0; j < repeat_of_iteration; ++j){
                SwapMap();
                RecountMap();
            }
            std::cout << "I recounted your map " + std::to_string(repeat_of_iteration) + " times" << std::endl;
            repeat_of_iteration = -1;
        }
    }
    first.PrintText('o');
    return 0; 
}

int Controller::Analiz(std::string input){
    
    std::string first_name = input.substr(0, 2);
    if (first_name == "-i"){
        return 1;
    }
    else if (first_name == "-o"){
        return 2;
    }
    else if (first_name[0] == '/'){
        return 3;
    }
    else if (first_name == "--"){
        if (input[2] == 'i'){
            return 4;
        }
        else if(input[2] == 'o'){
            return 5;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

void Controller :: Start(int argc, char* argv[]){
    std:: string address1;
    SaveNameOfRoot(argv[0]);
    if (argc > 1){
        if (PreRun(argv, argc) == 0){
            Run();
        }
    }
    else{
        Open(name_of_root + Example::GiveExample());
        Run();
    }
}

void Controller :: Show(Interface out, int amount){
    std::cout << "\033c";
    out.Output(mapNew_);
    for(int i = 0; i < amount; ++i){
        SwapMap();
        RecountMap();
        usleep(100000);
        std::cout << "\033c";
        out.Output(mapNew_);
        std::cout << std::endl;
    }
}

void Controller :: Run(){

    Interface first(size_x_, size_y_);
    ShowError(first);
    first.PrintText('b');
    bool run_game = true;
    while(run_game){
        std::string input;
        std::string data_file; 
        getline(std::cin, input, '\n');
        switch (first.Analyze(input)){
            case 1:
            data_file = input.substr(5);
            Save(data_file);
            first.PrintText('s');
            break;

            case 2:
            data_file = input.substr(5);
            repeat_of_iteration = GiveDigit(data_file);
            if (repeat_of_iteration != -1){
                Show(first, repeat_of_iteration);
            }
            else{
                first.PrintText('i');
            }
            break;
            case 3:
            run_game = false;
            break;

            case 4:
                first.PrintText('h');
            break;

            case -1:
                first.PrintText('e');
            break;

            case 0:
            error = 's';
            break;
            default:
            break;
        }
        ShowError(first);
    }

}

