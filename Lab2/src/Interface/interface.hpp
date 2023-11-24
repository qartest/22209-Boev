#pragma once
#include "../Game/game.hpp"

class Interface{

public: 
    Interface() = default;
    ~Interface() = default;
    void Output(Game game);
    int Analyze(std::string input);
    void PrintError(char error);
    void PrintText(char type);
    void Show(int amount, Game& game);
};
