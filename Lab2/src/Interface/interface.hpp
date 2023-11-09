#pragma once


class Interface{

    int size_x_;
    int size_y_;

public: 
    Interface() = default;
    Interface(int size_x, int size_y);
    ~Interface() = default;
    void Output(char* map);
    int Analyze(std::string input);
    void PrintError(char error);
    void PrintText(char type);
};
