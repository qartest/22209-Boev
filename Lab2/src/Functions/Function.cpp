#include "Function.hpp"

namespace Functions{
    int GiveDigit(std::string int_string){
        int digit = -1;
        for(int j = 0; j < int_string.size(); ++j){
            if(isdigit(int_string[j])){
                digit = ((digit + (digit == -1)) * 10) + (int_string[j]- '0');
            }
            else{
                break;
            }
        }
        return digit;    
    }

    int GiveY(int place, int size_x_){
        return place / size_x_;
    }
    int GiveX(int place, int size_x_){
        return place % size_x_;
    }
    int NumberCell(int coord_x, int coord_y, int size_x_){
        return size_x_ * coord_y + coord_x;
    }
    int SaveStep(int coord, int step, int capacity){
        return (coord + step) < 0? (coord + capacity + step) % capacity : (coord + step) % capacity;
    }
}