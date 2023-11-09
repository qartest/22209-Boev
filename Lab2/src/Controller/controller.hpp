#pragma once

#include <string>
#include "../Example/example.hpp"
#include "../Game/game.hpp"
#include "../Interface/interface.hpp"

class Controller : public Game{

    std::string name;
    char error;
    std::string name_of_root;
    int repeat_of_iteration;

    private:

    void SaveNameOfRoot(char* input);
    void Read(std::fstream file_in);
    void ReadCell(std::string input_line);
    void ReadName(std::string input_line);
    void Open(std::string address);
    void Save(std::string name);
    void Write(std::ofstream output, std::string name);
    void Show(Interface out, int amount);
    int GiveDigit(std::string int_string);
    void ShowError(Interface output);
    void Run();

    int PreRun(char * argv[], int argc);
    int Analiz(std::string input);
    public:

    void Start(int argc, char * argv[]); 
    
    char* GiveMap();

    Controller();
    Controller(int size_x, int size_y);
    ~Controller() = default;
};