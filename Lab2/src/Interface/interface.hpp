#pragma once
#include <variant>
#include <string>
#include "../Field/Field.hpp"



struct VDump
{   
    std::string out;
};

struct VExit
{};

struct VTick
{
    int repeat_of_iteration;
};

struct VSize
{
    int size;
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
    void Output(const Field& field);

    void ShowErrors(std::vector<Errors> error);
    const void ShowHelp() const;
    const void ShowDoNotMean() const;
    void ShowSave();

    my_var Input_Analysis();
};

