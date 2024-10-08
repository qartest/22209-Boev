#include "interface.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

namespace
{
void TopOutput(int size_x){
    for (int i = 0; i <= size_x + 1; ++i){
        std::cout << '_';
    }
    std::cout << std::endl;
}

void BottonOutput(int size_x){
    std::cout  << '|';
    for (int i = 1; i <= size_x; ++i){
        std::cout << '_';
    }
    std::cout  << '|';
    std::cout << std::endl;
}

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

int SizeParser(std::string input){
    std::vector<std::string> digits;
    std::stringstream ss (input);
    std::string tmp;
    int size = -1;
    while(std::getline(ss, tmp, ' ')){
        digits.push_back(tmp);
    }
    if (digits.size() < 1){
        return -1;
    }

    size = GiveDigit(digits[0]);
    
    if (size == -1){
        return -1;
    }
    return size;
}
}
const void Interface::ShowHelp() const{
    std::cout << "dump <filename> - save your universe" << std::endl;
    std::cout << "tick <n = 1> - do n steps on your game" << std::endl;
    std::cout << "exit - break the game" << std::endl;
    std::cout << "help - this command)" << std::endl;
}


void Interface::Output(const Field& field){

    std::cout << "\033c";
    int size = field.getSizeofside();
    std :: cout << std::endl;
    std :: cout << "Print help, if you don't know commands" << std::endl;
    TopOutput(size); 

    for (int j = 0; j < size; ++j){
        std::cout << '|';
        for (int i = 0; i < size; ++i){
            if(field.getState(i, j) == State::Alive){
                std:: cout << (char)42;
            }
            else{
                std::cout << ' ';
            } 
        }
        std::cout << '|';
        std :: cout << std::endl;
    }
    BottonOutput(size);

    std::cout << std::endl;
    std::cout << "All Okey!!!" << std::endl;
}

void Interface :: ShowSave(){
    std::cout << "I save your file" << std::endl;
}

const void Interface :: ShowDoNotMean() const{
    std::cout << "I don't know what you mean. Please, repeat" << std::endl;
}

UserInputResult Interface :: Input_Analysis(){
    std::string input;
    getline(std::cin, input, '\n');
    if (input.size() >= 4){
        std::string comand = input.substr(0, 4);
        if (comand == "dump"){

            return VDump{input.substr(5)};
        }
        else if(comand == "tick"){
            if (input.size() < 6){
                return VBad{};
            }
            int repeat_of_iterations = SizeParser(input.substr(5));
            if (repeat_of_iterations == -1){
                return VBad{};
            }
            return VTick{repeat_of_iterations};
        }
        else if(comand == "exit"){
            return VExit{};
        }
        else if(comand == "help"){
           return VHelp{};
        }
        else if (comand == "size"){
            if (input.size() < 6){
                return VBad{};
            }
            int size =  SizeParser(input.substr(5));
            if (size == -1){
                return VBad{};
            }
            return VSize{size};
        }
    }
    return VBad{};
}

 void Interface :: ShowErrors(std::vector<Errors> error) {

    for(auto i = error.begin(); i != error.end(); ++i){
        switch (*i)
        {
        case Errors :: CallProgrammIncorrectly:
            std::cout << "You called the program incorrectly" << std::endl;
        break;
        case Errors :: ProblemWithInputOfIteration:
            std::cout << "You have problem with input of iteration" << std::endl;
        break;
        case Errors :: Input:
            std::cout << "You have problem with input" << std::endl;
        break;
        case Errors :: CanNotOpenFile:
            std::cout << "I can't open your file" << std::endl;
        break;
        case Errors :: InputData:
            std::cout << "You have problem with input data" << std::endl;
        break;

        default:
            break;
        }
    }
}
