#include "game.hpp"


int Game :: SaveStep(int coord, int step, int capacity){
        return (coord + step) < 0? (coord + capacity + step) % capacity : (coord + step) % capacity;
    }

int Game :: NumberCell(int coord_x, int coord_y){
        return size_x_ * coord_y + coord_x;
    }

Game::Game(int size_x, int size_y){
    size_x_ = size_x;
    size_y_ = size_y;
    int size = size_x_ * size_y_;

    mapNew_ = (char*)calloc(size, sizeof(char));
    mapOld_ = (char*)calloc(size, sizeof(char));

    rule_s = std::vector<int>();
    rule_b = std::vector<int>();

}

Game :: ~Game(){
    delete(mapNew_);
    delete(mapOld_);
}

bool Game :: CheckOnePixel(int coord_x, int coord_y){
    int allLife = 0;
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            if ((j!= 0) || (i != 0)){
                int place_x = SaveStep(coord_x, j, size_x_);
                int place_y = SaveStep(coord_y, i, size_y_);
                if (mapOld_[NumberCell(place_x, place_y)] == 1){
                    allLife++;
                }
            }
        }
    }
    bool check = (rule_b.end() != std::find(rule_b.begin(), rule_b.end(), allLife));
    if (check){
        return true;
    }
    check = (rule_s.end() != std::find(rule_s.begin(), rule_s.end(), allLife));
    if (check && (mapOld_[NumberCell(coord_x, coord_y)] == 1)){
        return true;
    }
    return false;
    
}

void Game :: RecountMap(){
    for (int i = 0; i < size_y_; ++i){
        for (int j = 0; j < size_x_; ++j){
            int k = CheckOnePixel(j, i);
            if(CheckOnePixel(j, i)){
                mapNew_[NumberCell(j, i)] = 1;
            }
            else{
                mapNew_[NumberCell(j, i)] = 0;
            }
        }
    }
}

void Game :: SwapMap(){
    std::swap(mapNew_, mapOld_);
}