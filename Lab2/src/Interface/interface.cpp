#include <iostream>
#include "interface.hpp"


Interface::Interface(int size_x, int size_y){
    size_x_ = size_x;
    size_y_ = size_y;
}

void Interface::Output(char * map){
    int size = size_x_ * size_y_;
    std :: cout << std::endl;
    for(int i = 0; i < size; ++i){
        if (map[i] == 1){
            std:: cout << (char)42;
        }
        else{
            std:: cout << ' ';
        }
        
        if (((i + 1) % size_x_ == 0) && ((i + 1) < size)){
            std :: cout << std::endl;
        }
    }
}

int Interface:: Analyze(std::string input){
    if (input.size() >= 4){
        std::string comand = input.substr(0, 4);
        if (comand == "dump"){
            if (input.size() > 104){
                return 0;
            }
            return 1;
        }
        else if(comand == "tick"){

            return 2;
        }
        else if(comand == "exit"){
            return 3;
        }
        else if(comand == "help"){
           return 4;
        }
    }
    return -1;
}

void Interface :: PrintError(char error){
    switch (error){
        case '\0':
        break;

        case 'd':
        std::cout << "You have problem with input data" << std::endl;
        break;

        case 's':
        std::cout << "Bro, its name is so big... I don't save" << std::endl;
        break;

        case 'f':
        std::cout << "I can't open your file" << std::endl;
        break;

        case 'i':
        std::cout << "You have problem with input" << std::endl;
        break;

        case 'c':
        std::cout << "You called the program incorrectly" << std::endl;
        break;

        case 'r':
        std::cout << "You have problem with input of iteration" << std::endl;
        break;
        default:
        break;
    }
}

void Interface :: PrintText(char type){
    switch (type){
        case 'h':
            std::cout << "dump <filename> - save your universe" << std::endl;
            std::cout << "tick <n = 1> - do n steps on your game" << std::endl;
            std::cout << "exit - break the game" << std::endl;
            std::cout << "help - this command)" << std::endl;
        break;

        case 'e':
            std::cout << "I don't know what you mean. Please, repeat" << std::endl;
        break;

        case 'b':
            std::cout << "Hello, user! Let's go play!"<< std::endl;
        break;

        case 's':
            std::cout << "I save your file" << std::endl;
        break;

        case 'o':
            std::cout << "You didn't give the output file. Okey..." << std::endl;
        break;
        default:
            break;
    }
}