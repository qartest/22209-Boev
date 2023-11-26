#include "Controller/controller.hpp"
int SIZE = 30;

int main(int argc, char** argv){
    Game game(SIZE);
    Controller first;
    first.Start(argc, argv, game);
}