#include <iostream>
#include <vector>
#include <unistd.h>
#include "interface.hpp"

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
}

void Interface::Output(Game game){

    int size_x_ = game.GiveSizeX();
    int size_y_ = game.GiveSizeY();


    std :: cout << std::endl;
    std :: cout << "Print help, if you don't know commands" << std::endl;
    TopOutput(size_x_); 

    for (int j = 0; j < size_y_; ++j){
        std::cout << '|';
        for (int i = 0; i < size_x_; ++i){
            if(game.LiveOfCell(i, j)){
                std:: cout << (char)42;
            }
            else{
                std::cout << ' ';
            } 
        }
        std::cout << '|';
        std :: cout << std::endl;
    }
    BottonOutput(size_x_);
}

void Interface :: Show(int amount, Game& game){
    std::cout << "\033c";
    Output(game);
    for(int i = 0; i < amount; ++i){
        game.RecountMap();
        usleep(100000);
        std::cout << "\033c";
        Output(game);
        std::cout << std::endl;
        std::cout << "All Okey!!!" << std::endl;
    }
}

Analiz Interface:: Analyze(std::string input){
    if (input.size() >= 4){
        std::string comand = input.substr(0, 4);
        if (comand == "dump"){
            if (input.size() > 104){
                return Analiz::BadName;
            }
            return Analiz::Dump;
        }
        else if(comand == "tick"){
            if (input.size() < 6){
                return Analiz::Bad;
            }
            return Analiz::Tick;
        }
        else if(comand == "exit"){
            return Analiz::Exit;
        }
        else if(comand == "help"){
           return Analiz::Help;
        }
        else if (comand == "size"){
            if (input.size() < 6){
                return Analiz::Bad;
            }
            return Analiz::Size;
        }
    }
    return Analiz::Bad;
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