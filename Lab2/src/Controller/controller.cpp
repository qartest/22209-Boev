#include "controller.hpp"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <iostream>

Controller :: Controller(){
    name = " ";
    name_of_root = "";
    error = '\0';
    repeat_of_iteration = -1;
}

void Controller :: MakeError(char input){
    error = input;
}

int Controller :: SizeParser(int *x, int *y, std::string input){
    std::vector<std::string> digits;
    std::stringstream ss (input);
    std::string tmp;
    while(std::getline(ss, tmp, ' ')){
        digits.push_back(tmp);
    }
    if (digits.size() < 2){
        return -1;
    }

    *x = Functions::GiveDigit(digits[0]);
    *y = Functions::GiveDigit(digits[1]);
    
    if (*y == -1 || *x == -1){
        return -1;
    }
    return 0;
}

void Controller :: ShowError(Interface output){
    output.PrintError(error);
    error = '\0';
}

int Controller :: ReadCell(std::string input_line, Game& game){
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
        int place_x = Functions::SaveStep(0, coords[0], game.GiveSizeX());
        int place_y = Functions::SaveStep(0, coords[1], game.GiveSizeY());
        return Functions::NumberCell(place_x, place_y, game.GiveSizeX());
    } 
    return -1;  

}

void Controller :: ReadName(std::string input_line, Game& game){

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
                    game.TakeBorn(input_line[i] - '0');
                }
            }
        }
        if (input_line[i] == 'S'){
            for(;i< input_line.size(); ++i){
                if (isdigit(input_line[i])){
                    game.TakeSurval(input_line[i] - '0');
                }
            }
        }
    } 
 
}


void Controller :: Read(std::fstream file_in, Game& game){
    std::string input_line;

    while(getline(file_in, input_line, '\n')){
        if (input_line.size() == 0){
            break;
        }
        if(input_line[0] != '#'){
            int size_of_map = game.GiveMap().size();
            int number_of_cell = ReadCell(input_line, game);
            if (number_of_cell != -1){
                if (number_of_cell >= size_of_map){
                    game.GiveZeroMap(number_of_cell - size_of_map + 1);
                }
                game.TakeCell(number_of_cell);
            }
        }
        else{
            ReadName(input_line, game);
        }
    }
    game.GiveZeroMap(game.GiveSizeX() * game.GiveSizeY() - game.GiveMap().size());
}

void Controller :: Open(std::string address, Game& game){

    std::fstream file_in(address);
    if (file_in){
        Read(std::fstream (address), game);
    }
    else{
        error = 'f';
    }
}

void Controller :: Write(std::ofstream output, std::string name, Game& game){
    output << "#Life 1.06" << std::endl;
    output << "#N " << name << std::endl;
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

    for(int y = 0; y < game.GiveSizeY(); ++y){
        for (int x = 0; x < game.GiveSizeX(); ++x){
            if (game.LiveOfCell(Functions::NumberCell(x, y, game.GiveSizeX()))){
                output << std::to_string(x) << " " << std::to_string(y) << std::endl;
            }
        }
    }
}

void Controller :: Save(std::string name, Game& game){

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

void Controller :: SaveNameOfRoot(char* input){
    std::filesystem::path executablePath = std::filesystem::canonical(input);
    int count = 0;
    while (((*(--executablePath.end())).string() != "Lab2") && (count < 3)){
        executablePath = executablePath.parent_path();
        count++;
    }
     name_of_root = executablePath.string();
}

int Controller::PreRun(char * argv[], int argc, Game& game){

    Interface first;
    for (int i = 1; i < argc; ++i){
        switch(Analiz(std::string(argv[i]))){
            case 1:
            ++i;
            if (i < argc){
                repeat_of_iteration = Functions::GiveDigit(std::string(argv[i]));
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
                Save(std::string(argv[i]), game);
                first.PrintText('s');
                return 1;
            }
            else{
                error = 'c';
                i = argc;
            }
            break;

            case 3:
            Open(std::string(argv[i]),game);
            break;

            case 4:
            repeat_of_iteration = Functions::GiveDigit(std::string(argv[i]).substr(13));
            if (repeat_of_iteration == -1){
                error = 'r';
            }
            break;

            case 5:
            Save(std::string(argv[i]).substr(9), game);
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
                game.RecountMap();
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

void Controller :: Start(int argc, char* argv[], Game& game){
    std:: string address1;
    SaveNameOfRoot(argv[0]);
    if (argc > 1){
        if (PreRun(argv, argc, game) == 0){
            Run(game);
        }
    }
    else{
        Open(name_of_root + Example::GiveExample(), game);
        Run(game);
    }
}

void Controller :: Run(Game& game){

    Interface first;
    ShowError(first);
    first.PrintText('b');
    bool run_game = true;
    while(run_game){
        std::string input;
        std::string data_file; 
        int x = -1;
        int y = -1;
        getline(std::cin, input, '\n');
        switch (first.Analyze(input)){
            case 1:
            data_file = input.substr(5);
            Save(data_file, game);
            first.PrintText('s');
            break;

            case 2:
            data_file = input.substr(5);
            repeat_of_iteration = Functions::GiveDigit(data_file);
            if (repeat_of_iteration != -1){
                first.Show( repeat_of_iteration, game);
            }
            else{
                std::cout << "\033c";
                first.Output(game);
                error = 'i';
                first.PrintText('e');
            }
            break;
            case 3:
            run_game = false;
            break;

            case 4:
                std::cout << "\033c";
                first.Output(game);
                first.PrintText('h');
            break;
            case 5:
                data_file = input.substr(5);


                if (SizeParser(&x, &y, data_file) == -1){
                    std::cout << "\033c";
                    first.Output(game);
                    first.PrintText('e');
                }
                else{
                    game.RecountSize(x, y);
                    std::cout << "\033c";
                    first.Output(game);
                }
            break;
            case -1:
                std::cout << "\033c";
                first.Output(game);
                error = 'i';
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

