#pragma once
#include "../Game/game.hpp"
#include "stateofanaliz.hpp"


class Interface{

public: 
    Interface() = default;
    ~Interface() = default;
    void Output(Game game);
    Analiz Analyze(std::string input);
    void PrintError(char error);
    void PrintText(char type);
    void Show(int amount, Game& game);
};
