#include <iostream>

#include <Errors.hpp>

using namespace std;

InputFileErorr :: InputFileErorr(){
     cout << "Error with input file" << endl;
}

NotMono :: NotMono(){
     cout << "Input file is not Mono" << endl;
}

int NotMono :: what_index(){
    return 1;
}

NotPCM :: NotPCM(){
    cout << "Input file is not PCM" << endl;
}

int NotPCM :: what_index(){
    return 2;
}

Not16B :: Not16B(){
    cout << "Input file have not 16 bit depth" << endl;
}

int Not16B :: what_index(){
    return 3;
}

Not44100G :: Not44100G(){
    cout << "Input file have not samples per seconds == 44100" << endl; 
}

int Not44100G :: what_index(){
    return 4;
}

NotWav :: NotWav(){
    cout << "Input file is not wave" << endl;
}

int NotWav :: what_index(){
    return 5;
}

ConfigProblem :: ConfigProblem(){
    cout << "Config has a problem" << endl;
}

int ConfigProblem :: what_index(){
    return 6;
}

CalledFunctionError :: CalledFunctionError(){
    cout << "The function was called with an error" << endl;
}

BadWay :: BadWay(){
    cout << "The file have badway" << endl;
}

int BadWay :: what_index(){
    return -1;
}

NotWay :: NotWay(){
    cout << "The file have not the way for input or output files" << endl;
}

int NotWay :: what_index(){
    return -2;
}

ProgrammProblem :: ProgrammProblem(){
    cout<< "Program have a problem" << endl;
}

int ProgrammProblem :: what_index(){
    return -3;
}

