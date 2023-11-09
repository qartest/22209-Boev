#include "Controller/controller.hpp"

int SIZE_X = 30, SIZE_Y = 30;

int main(int argc, char** argv){
    Controller first(SIZE_X, SIZE_Y);
    first.Start(argc, argv);
}