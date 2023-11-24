#include "Controller/controller.hpp"

int SIZE_X = 30, SIZE_Y = 30;

int main(int argc, char** argv){
    Game game(SIZE_X, SIZE_Y);
    Controller first;
    first.Start(argc, argv, game);
}