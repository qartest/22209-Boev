#include "game.hpp"
#include <cmath>



Field :: Field(int size){
    field = std::vector<State>(size);
    std::fill(field.begin(), field.end(), State::Dead);

    size_of_side = (int)floor(sqrt(size));
}
State Field :: getState(int x, int y){
    return field[Functions::NumberCell(x, y, size_of_side)];
}

void Field :: setCell(int x, int y, State state){
    field[Functions::NumberCell(x, y, size_of_side)] = state;
}

int Field :: getSizeofside(){
    return size_of_side;
}
Game :: Game(int size){
    size_x_ = size;
    size_y_ = size;
    my_field = Field(size * size);
}

int Game :: GiveSizeX(){
    return my_field.getSizeofside();
}

int Game :: GiveSizeY(){
    return my_field.getSizeofside();
}
void Game :: TakeCell(int place, State state){
    my_field.setCell(Functions::GiveX(place, size_x_), Functions::GiveY(place, size_x_), state);
}


int Game :: GiveSizeRulers(){
    return rule_s.size();
}
bool Game :: GiveBorn(int number){
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
bool Game :: LiveOfCell(int x, int y){
    if (my_field.getState(x, y) == State::Alive){
        return true;
    }
    return false;
}

void Game :: RecountSize(int side){

    Field new_field(side * side);

    for (int i = 0; ((i < size_y_) && (i < side)); ++i){
        for (int j = 0; ((j < size_x_) && (j < side)); ++j){
            int new_map_cell = Functions::NumberCell(j, i, side);
            int old_map_cell = Functions::NumberCell(j, i, size_x_);
           new_field.setCell(j, i, my_field.getState(j, i));
        }
    }
    my_field = new_field;
    size_x_ = side;
    size_y_ = side;
}

bool Game :: CheckOnePixel(int coord_x, int coord_y){
    int allLife = 0;
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            if ((j!= 0) || (i != 0)){
                int place_x = Functions::SaveStep(coord_x, j, size_x_);
                int place_y = Functions::SaveStep(coord_y, i, size_y_);
                if (my_field.getState(place_x, place_y) == State::Alive){
                    allLife++;
                }
            }
        }
    }
    if (allLife < 8){
        if (rule_b[allLife] == 1){
            return true;
        }
        if ((rule_s[allLife] == 1) && (my_field.getState(coord_x, coord_y) == State::Alive)){
            return true;
        }
    }
    return false;
}

void Game :: RecountMap(){
    Field new_field(size_x_ * size_y_);

    std::vector<char> new_map(size_y_ * size_x_);
    for (int i = 0; i < size_y_; ++i){
        for (int j = 0; j < size_x_; ++j){
            if(CheckOnePixel(j, i)){
                new_field.setCell(j, i, State::Alive);
            }
            else{
                 new_field.setCell(j, i, State::Dead);
            }
        }
    }
    my_field = new_field;
}
