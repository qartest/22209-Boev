#include <fstream>
#include <sstream>
#include <filesystem>

#include "CSVParser.hpp"

 
int main(int argc, char* argv[]) {

    std::fstream file(std::filesystem::canonical(argv[0]).parent_path().parent_path().string() + "/src/test.csv");
    if(!file.is_open()){
        std::cout << "File don't open" << std::endl;
        return -1;
    }

    CSVParser<int, std::string> parser(file, 0, ',', '\n', '"');

    try {
        for (std::tuple<int, std::string> rs : parser) {
            std::cout << rs << std::endl;
        }
    } catch (DataError &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}