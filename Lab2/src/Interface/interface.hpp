#pragma once
#include <variant>
#include "../Game/game.hpp"


struct VDump
{   
    std::string out;
    Game& game;
    std::string name_of_root;
};

struct VExit
{};

struct VTick
{
};

struct VSize
{
};

struct VHelp
{
};

struct VBad
{
};

typedef std::variant<VBad, VDump, VExit, VHelp, VSize, VTick> my_var;

class Interface{

public: 
    Interface() = default;
    ~Interface() = default;
    void Output(Game game);

    void ShowErrors(std::vector<Errors> error);
    void Show(int amount, Game& game);
    const void ShowHelp() const;
    const void ShowDoNotMean() const;
    void ShowSave();

    my_var Input_Analysis(Game& game, std::string name_of_root);
};

