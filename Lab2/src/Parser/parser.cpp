#include "parser.hpp"

namespace{

struct Place{
    int x;
    int y;
}; 

int GiveDigit(std::string int_string){
    int digit = -1;
    for(int j = 0; j < int_string.size(); ++j){
        if(isdigit(int_string[j])){
            digit = ((digit + (digit == -1)) * 10) + (int_string[j]- '0');
        }
        else{
            break;
        }
    }
    return digit;    
}

int SaveStep(int coord, int step, int capacity){
    return (coord + step) < 0? (coord + capacity + step) % capacity : (coord + step) % capacity;
}

Place ReadCell(std::string input_line, call_input_data& game){
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
                game.errors.push_back(Errors::InputData);
                break;
            }
        }
    }
    
    Place out;
    out.x = coords[0];
    out.y = coords[1];
    if ((out.x > -1) && (out.y > -1)){
        out.x = SaveStep(0, out.x, game.size_of_side);
        out.y = SaveStep(0, out.y, game.size_of_side);
    } 

    return out;  

}

void ReadName(std::string input_line, call_input_data& game){

    for (int i = 0; i < input_line.size(); ++i){
        if (input_line[i] == 'N'){
            game.name = input_line.substr(3, input_line.size());
        }
        if (input_line[i] == 'B'){
            for(;i< input_line.size(); ++i){
                if (input_line[i] == '/'){
                    break;
                }
                if (isdigit(input_line[i])){
                    game.rule_b[input_line[i] - '0'] = 1;
                }
            }
        }
        if (input_line[i] == 'S'){
            for(;i< input_line.size(); ++i){
                if (isdigit(input_line[i])){
                    game.rule_s[input_line[i] - '0'] = 1;
                }
            }
        }
        if (input_line[i] == 'F'){
            int field = GiveDigit(input_line.substr(i+2));
            if (field != -1){
                game.size_of_side = field;
                game.my_field = Field(field*field);
            }
            else{
                game.save_run = false;
                game.errors.push_back(Errors::InputData);
            }
            break;
        }
    } 
 
}
void Read(std::fstream file_in, call_input_data& game){
    std::string input_line;

    while(getline(file_in, input_line, '\n')){
        if (input_line.size() == 0){
            break;
        }
        if(input_line[0] != '#'){
            
            Place number_of_cell = ReadCell(input_line, game);

            if (number_of_cell.x * number_of_cell.y > -1){
                game.my_field.setCell(number_of_cell.x, number_of_cell.y, State::Alive);
            }
        }
        else{
            ReadName(input_line, game);
        }
    }
}



StateOfCall AnalysisOfCall(std::string input){
    
    std::string first_name = input.substr(0, 2);
    if (first_name == "-i"){
        return StateOfCall::NumberOfRepeat2Words;
    }
    else if (first_name == "-o"){
        return StateOfCall::OutputFile2Word;
    }
    else if (first_name[0] == '/'){
        return StateOfCall::InputFile;
    }
    else if (first_name == "--"){
        if (input[2] == 'i'){
            return StateOfCall::NumberOfRepeat1Words;
        }
        else if(input[2] == 'o'){
            return StateOfCall::OutputFile1Word;
        }
        else{
            return StateOfCall::Bad;
        }
    }
    else{
        return StateOfCall::Bad;
    }
}

void SaveNameOfRoot(char* input_char, call_input_data& input){
    std::filesystem::path executablePath = std::filesystem::canonical(input_char);
    int count = 0;
    while (((*(--executablePath.end())).string() != "Lab2") && (count < 3)){
        executablePath = executablePath.parent_path();
        count++;
    }
    input.name_of_root = executablePath.string();
}
}


namespace Parser{
    call_input_data ParsingInput(int argc, char** argv){
        call_input_data output;
        output.save_run = true;
        output.mode = Mode::Online;
        std::string data;

        for (int i = 1; i < argc; ++i){
            switch(AnalysisOfCall(std::string(argv[i]))){
                case StateOfCall::NumberOfRepeat2Words:
                    ++i;
                    if (i < argc){
                        output.repeat_of_iteration = GiveDigit(std::string(argv[i]));
                        if (output.repeat_of_iteration == -1){
                            output.errors.push_back(Errors::ProblemWithInputOfIteration);
                        }
                        output.mode = Mode::Online;
                    }
                    else{
                        output.errors.push_back(Errors::CallProgrammIncorrectly);
                        i = argc;
                        output.save_run = false;
                    }
                break;

                case StateOfCall::OutputFile2Word:
                    ++i;
                    output.output_name = std::string(argv[i]);
                    output.mode = Mode::Offline;
                break;

                case StateOfCall::InputFile:

                    data = std::string((argv[i]));

                    if (std::fstream(std::string(argv[i]), std::ios::in).is_open()){
                        Read(std::fstream(std::string(argv[i]), std::ios::in), output);
                    }
                    else{
                        output.errors.push_back(Errors::CanNotOpenFile);
                        output.save_run = false;
                    }
                    output.mode = Mode::Online;
                    
                break;

                case StateOfCall::NumberOfRepeat1Words:
                    output.repeat_of_iteration = GiveDigit(std::string(argv[i]).substr(13));
                    if (output.repeat_of_iteration == -1){
                        output.errors.push_back(Errors::ProblemWithInputOfIteration);
                    }
                break;

                case StateOfCall::OutputFile1Word:
                    output.output_name = std::string(argv[i]).substr(9);
                    output.mode = Mode::Offline;

                break;

                case StateOfCall::Bad:
                    output.errors.push_back(Errors::CallProgrammIncorrectly);
                    i = argc;
                    output.save_run = false;
                break;
            }
        }
        
        if (argc <= 1){
            SaveNameOfRoot(argv[0], output);
            std::string example = output.name_of_root + Example::GiveExample();
            Read(std::fstream(example, std::ios::in), output);

        }    
    return output;
    }

}