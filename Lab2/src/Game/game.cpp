#include "game.hpp"

Game::Game(int size_x, int size_y){
    size_x_ = size_x;
    size_y_ = size_y;
}

std::vector<char> Game :: GiveMap(){
    return map_;
}

int Game :: GiveSizeX(){
    return size_x_;
}

int Game :: GiveSizeY(){
    return size_y_;
}
void Game :: TakeCell(int place){
    map_[place] = 1;
}
 void Game :: GiveZeroMap(int number){
    for (int i = 0; i < number; ++i){
        map_.push_back(0);
    }
 }

int Game::GiveSizeRulers(){
    return rule_s.size();
}
bool Game:: GiveBorn(int number){
    return rule_b[number];
}
bool Game :: GiveSurval(int number){
    return rule_s[number];
}
void Game :: TakeSurval(int number){
    if (number < rule_s.size()){
        rule_s[number] = 1;
    }
}

void Game :: TakeBorn(int number){
    if (number < rule_b.size()){
        rule_b[number] = 1;
    }
}
bool Game :: LiveOfCell(int number){
    if (map_[number] == 1){
        return true;
    }
    return false;
}

void Game:: RecountSize(int x, int y){
    std::vector<char> new_map(y * x);

    for (int i = 0; i < y * x; ++i){
        new_map[i] = 0;
    }

    for (int i = 0; ((i < size_y_) && (i < y)); ++i){
        for (int j = 0; ((j < size_x_) && (j < x)); ++j){
            int new_map_cell = Functions::NumberCell(j, i, x);
            int old_map_cell = Functions::NumberCell(j, i, size_x_);
           new_map[Functions::NumberCell(j, i, x)] = map_[Functions::NumberCell(j, i, size_x_)];
        }
    }
    map_ = new_map;
    size_x_ = x;
    size_y_ = y;
}

bool Game :: CheckOnePixel(int coord_x, int coord_y){
    int allLife = 0;
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            if ((j!= 0) || (i != 0)){
                int place_x = Functions::SaveStep(coord_x, j, size_x_);
                int place_y = Functions::SaveStep(coord_y, i, size_y_);
                if (map_[Functions::NumberCell(place_x, place_y, size_x_)] == 1){
                    allLife++;
                }
            }
        }
    }
    if (allLife < 8){
        if (rule_b[allLife] == 1){
            return true;
        }
        if ((rule_s[allLife] == 1) && (map_[Functions::NumberCell(coord_x, coord_y, size_x_)] == 1)){
            return true;
        }
    }
    return false;
}

void Game :: RecountMap(){
    std::vector<char> new_map(size_y_ * size_x_);
    for (int i = 0; i < size_y_; ++i){
        for (int j = 0; j < size_x_; ++j){
            int place = Functions::NumberCell(j, i, size_x_);
            if(CheckOnePixel(j, i)){
                new_map[Functions::NumberCell(j, i, size_x_)] = 1;
            }
            else{
                new_map[Functions::NumberCell(j, i, size_x_)] = 0;
            }
        }
    }
    map_ = new_map;
}
