#include "example.hpp"
#include <vector>
#include <cstdlib>

const std::vector <std::string> examples_base ={
    "/src/Example/Examples/c.txt",
    "/src/Example/Examples/first.txt",
    "/src/Example/Examples/second.txt",
    "/src/Example/Examples/third.txt",
    "/src/Example/Examples/a.txt",
    "/src/Example/Examples/b.txt"
};  


std::string Example::GiveExample(){
    srand((unsigned) time(NULL));
    int digit_of_string = std::rand() % examples_base.size();
    return examples_base[digit_of_string];
}