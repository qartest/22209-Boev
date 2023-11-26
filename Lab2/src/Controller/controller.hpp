#pragma once

#include <string>
#include "../Example/example.hpp"
#include "../Interface/interface.hpp"
#include "stateofcall.hpp"



class Controller{

    std::string name;
    char error;
    std::string name_of_root;
    int repeat_of_iteration;

    public:
    void MakeError(char input);

    private:

    void SaveNameOfRoot(char* input);

    void Read(std::fstream file_in, Game& game);
    int ReadCell(std::string input_line, Game& game);
    void ReadName(std::string input_line, Game& game);

    void Open(std::string address, Game& game);

    void Save(std::string name, Game& game);
    void Write(std::ofstream output, std::string name, Game& game);

    void Show(Interface out, int amount, Game& game);
    void ShowError(Interface output);

    void Run(Game& game);
    int PreRun(char * argv[], int argc, Game& game);
    StateOfCall AnalizOfCall(std::string input);

    int SizeParser(int *size, std::string input);
    void RecountSize(int size, Game game);
    
    public:

    void Start(int argc, char * argv[], Game& game); 
    Controller();
    ~Controller() = default;
};