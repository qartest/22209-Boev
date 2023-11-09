#pragma once

#include <memory>
#include<vector>
#include <algorithm> 


class Game{

private:
    bool CheckOnePixel(int coord_x, int coord_y);

public:
    Game() = default;
    Game(int size_x, int size_y);
    ~Game();

protected:

    int SaveStep(int coord, int step, int capacity);
    int NumberCell(int coord_x, int coord_y);
    void SwapMap();
    void RecountMap();

    char* mapOld_;
    char* mapNew_;

    std::vector<int> rule_s;
    std::vector<int> rule_b;

    int size_x_;
    int size_y_;

};