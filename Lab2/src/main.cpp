#include "Controller/controller.hpp"
#include "Parser/parser.hpp"

int main(int argc, char** argv){
    call_input_data input = Parser::ParsingInput(argc, argv);

    Game game(input);
    Controller controller(input);
    controller.Run(game);
}