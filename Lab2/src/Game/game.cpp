#include "game.hpp"
#include <cmath>

namespace{
    int NumberCell(int coord_x, int coord_y, int size_x_){
        return size_x_ * coord_y + coord_x; 
    }
    int SaveStep(int coord, int step, int capacity){
        return (coord + step) < 0? (coord + capacity + step) % capacity : (coord + step) % capacity;
    }

}

Field :: Field(int size){

    size_of_side = (int)floor(sqrt(size));

    field = std::vector<State>(size_of_side * size_of_side);
    std::fill(field.begin(), field.end(), State::Dead);
}

State Field :: getState(int x, int y){
    return field[NumberCell(x, y, size_of_side)];
}

void Field :: setCell(int x, int y, State state){
    field[NumberCell(x, y, size_of_side)] = state;
}

int Field :: getSizeofside(){
    return size_of_side;
}

int Game :: GiveSizeRulers(){
    return rule_b.size();
}

const Field Game :: GiveField() const{
    return my_field;
}
bool Game :: GiveBorn(int i){
    if ((i > 0) && (i < rule_b.size())){
        return (rule_b[i] == 1);
    }
    return false;
}

bool Game :: GiveSurval(int i){
    if ((i > 0) && (i < rule_s.size())){
        return (rule_s[i] == 1);
    }
    return false;
}

Game :: Game(call_input_data input){
    if (input.save_run){
        rule_b = input.rule_b;
        rule_s = input.rule_s;

        my_field = input.my_field;

    }
}

void Game :: RecountSize(int side){
    int size_of_side = my_field.getSizeofside();
    Field new_field(side * side);

    for (int i = 0; ((i < size_of_side) && (i < side)); ++i){
        for (int j = 0; ((j < size_of_side) && (j < side)); ++j){
            int new_map_cell = NumberCell(j, i, side);
            int old_map_cell = NumberCell(j, i, size_of_side);
           new_field.setCell(j, i, my_field.getState(j, i));
        }
    }
    my_field = new_field;

}

bool Game :: CheckOnePixel(int coord_x, int coord_y){
    int size_of_side = my_field.getSizeofside();
    int allLife = 0;
    for (int i = -1; i < 2; ++i){
        for (int j = -1; j < 2; ++j){
            if ((j!= 0) || (i != 0)){
                int place_x = SaveStep(coord_x, j, size_of_side);
                int place_y = SaveStep(coord_y, i, size_of_side);
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
    int size_of_side = my_field.getSizeofside();
    Field new_field(size_of_side * size_of_side);

    for (int i = 0; i < size_of_side; ++i){
        for (int j = 0; j < size_of_side; ++j){
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
