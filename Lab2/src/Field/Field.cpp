#include"Field.hpp"
#include <cmath>


namespace{
    int NumberCell(int coord_x, int coord_y, int size_x_){
        return size_x_ * coord_y + coord_x; 
    }
}

Field :: Field(int size){

    size_of_side = static_cast<int>(floor(sqrt(size)));

    field = std::vector<State>(size_of_side * size_of_side);
    std::fill(field.begin(), field.end(), State::Dead);
}

State Field :: getState(int x, int y) const{
    return field[NumberCell(x, y, size_of_side)];
}

void Field :: setCell(int x, int y, State state){
    field[NumberCell(x, y, size_of_side)] = state;
}

int Field :: getSizeofside() const{
    return size_of_side;
}